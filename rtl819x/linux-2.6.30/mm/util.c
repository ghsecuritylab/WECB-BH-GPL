#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/sched.h>
#include <linux/tracepoint.h>
#include <asm/uaccess.h>

/**
 * kstrdup - allocate space for and copy an existing string
 * @s: the string to duplicate
 * @gfp: the GFP mask used in the kmalloc() call when allocating memory
 */
char *kstrdup(const char *s, gfp_t gfp)
{
	size_t len;
	char *buf;

	if (!s)
		return NULL;

	len = strlen(s) + 1;
	buf = kmalloc_track_caller(len, gfp);
	if (buf)
		memcpy(buf, s, len);
	return buf;
}
EXPORT_SYMBOL(kstrdup);

/**
 * kstrndup - allocate space for and copy an existing string
 * @s: the string to duplicate
 * @max: read at most @max chars from @s
 * @gfp: the GFP mask used in the kmalloc() call when allocating memory
 */
char *kstrndup(const char *s, size_t max, gfp_t gfp)
{
	size_t len;
	char *buf;

	if (!s)
		return NULL;

	len = strnlen(s, max);
	buf = kmalloc_track_caller(len+1, gfp);
	if (buf) {
		memcpy(buf, s, len);
		buf[len] = '\0';
	}
	return buf;
}
EXPORT_SYMBOL(kstrndup);

/**
 * kmemdup - duplicate region of memory
 *
 * @src: memory region to duplicate
 * @len: memory region length
 * @gfp: GFP mask to use
 */
void *kmemdup(const void *src, size_t len, gfp_t gfp)
{
	void *p;

	p = kmalloc_track_caller(len, gfp);
	if (p)
		memcpy(p, src, len);
	return p;
}
EXPORT_SYMBOL(kmemdup);

/**
 * memdup_user - duplicate memory region from user space
 *
 * @src: source address in user space
 * @len: number of bytes to copy
 *
 * Returns an ERR_PTR() on failure.
 */
void *memdup_user(const void __user *src, size_t len)
{
	void *p;

	/*
	 * Always use GFP_KERNEL, since copy_from_user() can sleep and
	 * cause pagefault, which makes it pointless to use GFP_NOFS
	 * or GFP_ATOMIC.
	 */
	p = kmalloc_track_caller(len, GFP_KERNEL);
	if (!p)
		return ERR_PTR(-ENOMEM);

	if (copy_from_user(p, src, len)) {
		kfree(p);
		return ERR_PTR(-EFAULT);
	}

	return p;
}
EXPORT_SYMBOL(memdup_user);

/**
 * __krealloc - like krealloc() but don't free @p.
 * @p: object to reallocate memory for.
 * @new_size: how many bytes of memory are required.
 * @flags: the type of memory to allocate.
 *
 * This function is like krealloc() except it never frees the originally
 * allocated buffer. Use this if you don't want to free the buffer immediately
 * like, for example, with RCU.
 */
void *__krealloc(const void *p, size_t new_size, gfp_t flags)
{
	void *ret;
	size_t ks = 0;

	if (unlikely(!new_size))
		return ZERO_SIZE_PTR;

	if (p)
		ks = ksize(p);

	if (ks >= new_size)
		return (void *)p;

	ret = kmalloc_track_caller(new_size, flags);
	if (ret && p)
		memcpy(ret, p, ks);

	return ret;
}
EXPORT_SYMBOL(__krealloc);

/**
 * krealloc - reallocate memory. The contents will remain unchanged.
 * @p: object to reallocate memory for.
 * @new_size: how many bytes of memory are required.
 * @flags: the type of memory to allocate.
 *
 * The contents of the object pointed to are preserved up to the
 * lesser of the new and old sizes.  If @p is %NULL, krealloc()
 * behaves exactly like kmalloc().  If @size is 0 and @p is not a
 * %NULL pointer, the object pointed to is freed.
 */
void *krealloc(const void *p, size_t new_size, gfp_t flags)
{
	void *ret;

	if (unlikely(!new_size)) {
		kfree(p);
		return ZERO_SIZE_PTR;
	}

	ret = __krealloc(p, new_size, flags);
	if (ret && p != ret)
		kfree(p);

	return ret;
}
EXPORT_SYMBOL(krealloc);

/**
 * kzfree - like kfree but zero memory
 * @p: object to free memory of
 *
 * The memory of the object @p points to is zeroed before freed.
 * If @p is %NULL, kzfree() does nothing.
 */
void kzfree(const void *p)
{
	size_t ks;
	void *mem = (void *)p;

	if (unlikely(ZERO_OR_NULL_PTR(mem)))
		return;
	ks = ksize(mem);
	memset(mem, 0, ks);
	kfree(mem);
}
EXPORT_SYMBOL(kzfree);

/*
 * strndup_user - duplicate an existing string from user space
 * @s: The string to duplicate
 * @n: Maximum number of bytes to copy, including the trailing NUL.
 */
char *strndup_user(const char __user *s, long n)
{
	char *p;
	long length;

	length = strnlen_user(s, n);

	if (!length)
		return ERR_PTR(-EFAULT);

	if (length > n)
		return ERR_PTR(-EINVAL);

	p = kmalloc(length, GFP_KERNEL);

	if (!p)
		return ERR_PTR(-ENOMEM);

	if (copy_from_user(p, s, length)) {
		kfree(p);
		return ERR_PTR(-EFAULT);
	}

	p[length - 1] = '\0';

	return p;
}
EXPORT_SYMBOL(strndup_user);

#ifndef HAVE_ARCH_PICK_MMAP_LAYOUT
void arch_pick_mmap_layout(struct mm_struct *mm)
{
	mm->mmap_base = TASK_UNMAPPED_BASE;
	mm->get_unmapped_area = arch_get_unmapped_area;
	mm->unmap_area = arch_unmap_area;
}
#endif

/**
 * get_user_pages_fast() - pin user pages in memory
 * @start:	starting user address
 * @nr_pages:	number of pages from start to pin
 * @write:	whether pages will be written to
 * @pages:	array that receives pointers to the pages pinned.
 *		Should be at least nr_pages long.
 *
 * Attempt to pin user pages in memory without taking mm->mmap_sem.
 * If not successful, it will fall back to taking the lock and
 * calling get_user_pages().
 *
 * Returns number of pages pinned. This may be fewer than the number
 * requested. If nr_pages is 0 or negative, returns 0. If no pages
 * were pinned, returns -errno.
 */
int __attribute__((weak)) get_user_pages_fast(unsigned long start,
				int nr_pages, int write, struct page **pages)
{
	struct mm_struct *mm = current->mm;
	int ret;

	down_read(&mm->mmap_sem);
	ret = get_user_pages(current, mm, start, nr_pages,
					write, 0, pages, NULL);
	up_read(&mm->mmap_sem);

	return ret;
}
EXPORT_SYMBOL_GPL(get_user_pages_fast);

/* Tracepoints definitions. */
DEFINE_TRACE(kmalloc);
DEFINE_TRACE(kmem_cache_alloc);
DEFINE_TRACE(kmalloc_node);
DEFINE_TRACE(kmem_cache_alloc_node);
DEFINE_TRACE(kfree);
DEFINE_TRACE(kmem_cache_free);

EXPORT_TRACEPOINT_SYMBOL(kmalloc);
EXPORT_TRACEPOINT_SYMBOL(kmem_cache_alloc);
EXPORT_TRACEPOINT_SYMBOL(kmalloc_node);
EXPORT_TRACEPOINT_SYMBOL(kmem_cache_alloc_node);
EXPORT_TRACEPOINT_SYMBOL(kfree);
EXPORT_TRACEPOINT_SYMBOL(kmem_cache_free);
