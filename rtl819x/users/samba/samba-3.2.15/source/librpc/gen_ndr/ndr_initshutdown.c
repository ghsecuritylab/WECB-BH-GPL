/* parser auto-generated by pidl */

#include "includes.h"
#include "librpc/gen_ndr/ndr_initshutdown.h"

static enum ndr_err_code ndr_push_initshutdown_String_sub(struct ndr_push *ndr, int ndr_flags, const struct initshutdown_String_sub *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, strlen_m_term(r->name)));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_LEN4|LIBNDR_FLAG_STR_NOTERM);
			NDR_CHECK(ndr_push_string(ndr, NDR_SCALARS, r->name));
			ndr->flags = _flags_save_string;
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_initshutdown_String_sub(struct ndr_pull *ndr, int ndr_flags, struct initshutdown_String_sub *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->name_size));
		{
			uint32_t _flags_save_string = ndr->flags;
			ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_LEN4|LIBNDR_FLAG_STR_NOTERM);
			NDR_CHECK(ndr_pull_string(ndr, NDR_SCALARS, &r->name));
			ndr->flags = _flags_save_string;
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_initshutdown_String_sub(struct ndr_print *ndr, const char *name, const struct initshutdown_String_sub *r)
{
	ndr_print_struct(ndr, name, "initshutdown_String_sub");
	ndr->depth++;
	ndr_print_uint32(ndr, "name_size", (ndr->flags & LIBNDR_PRINT_SET_VALUES)?strlen_m_term(r->name):r->name_size);
	ndr_print_string(ndr, "name", r->name);
	ndr->depth--;
}

_PUBLIC_ enum ndr_err_code ndr_push_initshutdown_String(struct ndr_push *ndr, int ndr_flags, const struct initshutdown_String *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, strlen_m(r->name->name) * 2));
		NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, strlen_m_term(r->name->name) * 2));
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->name));
	}
	if (ndr_flags & NDR_BUFFERS) {
		if (r->name) {
			NDR_CHECK(ndr_push_initshutdown_String_sub(ndr, NDR_SCALARS, r->name));
		}
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_initshutdown_String(struct ndr_pull *ndr, int ndr_flags, struct initshutdown_String *r)
{
	uint32_t _ptr_name;
	TALLOC_CTX *_mem_save_name_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, &r->name_len));
		NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, &r->name_size));
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_name));
		if (_ptr_name) {
			NDR_PULL_ALLOC(ndr, r->name);
		} else {
			r->name = NULL;
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		if (r->name) {
			_mem_save_name_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->name, 0);
			NDR_CHECK(ndr_pull_initshutdown_String_sub(ndr, NDR_SCALARS, r->name));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_name_0, 0);
		}
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_initshutdown_String(struct ndr_print *ndr, const char *name, const struct initshutdown_String *r)
{
	ndr_print_struct(ndr, name, "initshutdown_String");
	ndr->depth++;
	ndr_print_uint16(ndr, "name_len", (ndr->flags & LIBNDR_PRINT_SET_VALUES)?strlen_m(r->name->name) * 2:r->name_len);
	ndr_print_uint16(ndr, "name_size", (ndr->flags & LIBNDR_PRINT_SET_VALUES)?strlen_m_term(r->name->name) * 2:r->name_size);
	ndr_print_ptr(ndr, "name", r->name);
	ndr->depth++;
	if (r->name) {
		ndr_print_initshutdown_String_sub(ndr, "name", r->name);
	}
	ndr->depth--;
	ndr->depth--;
}

static enum ndr_err_code ndr_push_initshutdown_Init(struct ndr_push *ndr, int flags, const struct initshutdown_Init *r)
{
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.hostname));
		if (r->in.hostname) {
			NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, *r->in.hostname));
		}
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.message));
		if (r->in.message) {
			NDR_CHECK(ndr_push_initshutdown_String(ndr, NDR_SCALARS|NDR_BUFFERS, r->in.message));
		}
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->in.timeout));
		NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->in.force_apps));
		NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->in.reboot));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_initshutdown_Init(struct ndr_pull *ndr, int flags, struct initshutdown_Init *r)
{
	uint32_t _ptr_hostname;
	uint32_t _ptr_message;
	TALLOC_CTX *_mem_save_hostname_0;
	TALLOC_CTX *_mem_save_message_0;
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_hostname));
		if (_ptr_hostname) {
			NDR_PULL_ALLOC(ndr, r->in.hostname);
		} else {
			r->in.hostname = NULL;
		}
		if (r->in.hostname) {
			_mem_save_hostname_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.hostname, 0);
			NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, r->in.hostname));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_hostname_0, 0);
		}
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_message));
		if (_ptr_message) {
			NDR_PULL_ALLOC(ndr, r->in.message);
		} else {
			r->in.message = NULL;
		}
		if (r->in.message) {
			_mem_save_message_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.message, 0);
			NDR_CHECK(ndr_pull_initshutdown_String(ndr, NDR_SCALARS|NDR_BUFFERS, r->in.message));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_message_0, 0);
		}
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->in.timeout));
		NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->in.force_apps));
		NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->in.reboot));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_initshutdown_Init(struct ndr_print *ndr, const char *name, int flags, const struct initshutdown_Init *r)
{
	ndr_print_struct(ndr, name, "initshutdown_Init");
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "initshutdown_Init");
		ndr->depth++;
		ndr_print_ptr(ndr, "hostname", r->in.hostname);
		ndr->depth++;
		if (r->in.hostname) {
			ndr_print_uint16(ndr, "hostname", *r->in.hostname);
		}
		ndr->depth--;
		ndr_print_ptr(ndr, "message", r->in.message);
		ndr->depth++;
		if (r->in.message) {
			ndr_print_initshutdown_String(ndr, "message", r->in.message);
		}
		ndr->depth--;
		ndr_print_uint32(ndr, "timeout", r->in.timeout);
		ndr_print_uint8(ndr, "force_apps", r->in.force_apps);
		ndr_print_uint8(ndr, "reboot", r->in.reboot);
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "initshutdown_Init");
		ndr->depth++;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_initshutdown_Abort(struct ndr_push *ndr, int flags, const struct initshutdown_Abort *r)
{
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.server));
		if (r->in.server) {
			NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, *r->in.server));
		}
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_initshutdown_Abort(struct ndr_pull *ndr, int flags, struct initshutdown_Abort *r)
{
	uint32_t _ptr_server;
	TALLOC_CTX *_mem_save_server_0;
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_server));
		if (_ptr_server) {
			NDR_PULL_ALLOC(ndr, r->in.server);
		} else {
			r->in.server = NULL;
		}
		if (r->in.server) {
			_mem_save_server_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.server, 0);
			NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, r->in.server));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_server_0, 0);
		}
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_initshutdown_Abort(struct ndr_print *ndr, const char *name, int flags, const struct initshutdown_Abort *r)
{
	ndr_print_struct(ndr, name, "initshutdown_Abort");
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "initshutdown_Abort");
		ndr->depth++;
		ndr_print_ptr(ndr, "server", r->in.server);
		ndr->depth++;
		if (r->in.server) {
			ndr_print_uint16(ndr, "server", *r->in.server);
		}
		ndr->depth--;
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "initshutdown_Abort");
		ndr->depth++;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static enum ndr_err_code ndr_push_initshutdown_InitEx(struct ndr_push *ndr, int flags, const struct initshutdown_InitEx *r)
{
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.hostname));
		if (r->in.hostname) {
			NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, *r->in.hostname));
		}
		NDR_CHECK(ndr_push_unique_ptr(ndr, r->in.message));
		if (r->in.message) {
			NDR_CHECK(ndr_push_initshutdown_String(ndr, NDR_SCALARS|NDR_BUFFERS, r->in.message));
		}
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->in.timeout));
		NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->in.force_apps));
		NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->in.reboot));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->in.reason));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_WERROR(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_initshutdown_InitEx(struct ndr_pull *ndr, int flags, struct initshutdown_InitEx *r)
{
	uint32_t _ptr_hostname;
	uint32_t _ptr_message;
	TALLOC_CTX *_mem_save_hostname_0;
	TALLOC_CTX *_mem_save_message_0;
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_hostname));
		if (_ptr_hostname) {
			NDR_PULL_ALLOC(ndr, r->in.hostname);
		} else {
			r->in.hostname = NULL;
		}
		if (r->in.hostname) {
			_mem_save_hostname_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.hostname, 0);
			NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, r->in.hostname));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_hostname_0, 0);
		}
		NDR_CHECK(ndr_pull_generic_ptr(ndr, &_ptr_message));
		if (_ptr_message) {
			NDR_PULL_ALLOC(ndr, r->in.message);
		} else {
			r->in.message = NULL;
		}
		if (r->in.message) {
			_mem_save_message_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->in.message, 0);
			NDR_CHECK(ndr_pull_initshutdown_String(ndr, NDR_SCALARS|NDR_BUFFERS, r->in.message));
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_message_0, 0);
		}
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->in.timeout));
		NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->in.force_apps));
		NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->in.reboot));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->in.reason));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_WERROR(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_initshutdown_InitEx(struct ndr_print *ndr, const char *name, int flags, const struct initshutdown_InitEx *r)
{
	ndr_print_struct(ndr, name, "initshutdown_InitEx");
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "initshutdown_InitEx");
		ndr->depth++;
		ndr_print_ptr(ndr, "hostname", r->in.hostname);
		ndr->depth++;
		if (r->in.hostname) {
			ndr_print_uint16(ndr, "hostname", *r->in.hostname);
		}
		ndr->depth--;
		ndr_print_ptr(ndr, "message", r->in.message);
		ndr->depth++;
		if (r->in.message) {
			ndr_print_initshutdown_String(ndr, "message", r->in.message);
		}
		ndr->depth--;
		ndr_print_uint32(ndr, "timeout", r->in.timeout);
		ndr_print_uint8(ndr, "force_apps", r->in.force_apps);
		ndr_print_uint8(ndr, "reboot", r->in.reboot);
		ndr_print_uint32(ndr, "reason", r->in.reason);
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "initshutdown_InitEx");
		ndr->depth++;
		ndr_print_WERROR(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static const struct ndr_interface_call initshutdown_calls[] = {
	{
		"initshutdown_Init",
		sizeof(struct initshutdown_Init),
		(ndr_push_flags_fn_t) ndr_push_initshutdown_Init,
		(ndr_pull_flags_fn_t) ndr_pull_initshutdown_Init,
		(ndr_print_function_t) ndr_print_initshutdown_Init,
		false,
	},
	{
		"initshutdown_Abort",
		sizeof(struct initshutdown_Abort),
		(ndr_push_flags_fn_t) ndr_push_initshutdown_Abort,
		(ndr_pull_flags_fn_t) ndr_pull_initshutdown_Abort,
		(ndr_print_function_t) ndr_print_initshutdown_Abort,
		false,
	},
	{
		"initshutdown_InitEx",
		sizeof(struct initshutdown_InitEx),
		(ndr_push_flags_fn_t) ndr_push_initshutdown_InitEx,
		(ndr_pull_flags_fn_t) ndr_pull_initshutdown_InitEx,
		(ndr_print_function_t) ndr_print_initshutdown_InitEx,
		false,
	},
	{ NULL, 0, NULL, NULL, NULL, false }
};

static const char * const initshutdown_endpoint_strings[] = {
	"ncacn_np:[\\pipe\\InitShutdown]", 
};

static const struct ndr_interface_string_array initshutdown_endpoints = {
	.count	= 1,
	.names	= initshutdown_endpoint_strings
};

static const char * const initshutdown_authservice_strings[] = {
	"host", 
};

static const struct ndr_interface_string_array initshutdown_authservices = {
	.count	= 1,
	.names	= initshutdown_authservice_strings
};


const struct ndr_interface_table ndr_table_initshutdown = {
	.name		= "initshutdown",
	.syntax_id	= {
		{0x894de0c0,0x0d55,0x11d3,{0xa3,0x22},{0x00,0xc0,0x4f,0xa3,0x21,0xa1}},
		NDR_INITSHUTDOWN_VERSION
	},
	.helpstring	= NDR_INITSHUTDOWN_HELPSTRING,
	.num_calls	= 3,
	.calls		= initshutdown_calls,
	.endpoints	= &initshutdown_endpoints,
	.authservices	= &initshutdown_authservices
};

