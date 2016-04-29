/* header auto-generated by pidl */

#include <stdint.h>

#ifndef _HEADER_notify
#define _HEADER_notify

struct notify_entry {
	struct server_id server;
	uint32_t filter;
	uint32_t subdir_filter;
	const char * path;/* [flag(LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM)] */
	uint32_t path_len;
	void* private_data;
}/* [public] */;

struct notify_depth {
	uint32_t max_mask;
	uint32_t max_mask_subdir;
	uint32_t num_entries;
	struct notify_entry *entries;
};

struct notify_array {
	uint32_t num_depths;
	struct notify_depth *depth;
}/* [public] */;

struct notify_event {
	uint32_t action;
	const char * path;/* [flag(LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM)] */
	void* private_data;
}/* [public] */;

#endif /* _HEADER_notify */
