#ifndef __WRAPPER_H__
#define __WRAPPER_H__

// SPDX-License-Identifier : BSD-3-Clause-Attribution


#ifdef __cplusplus
	#define EXPORT_C extern "C"
#else
	#define EXPORT_C
#endif

EXPORT_C typedef struct dops_handle
{
	void *dops_ptr;
} dops_handle_t;

EXPORT_C void create_dops_handle(dops_handle_t **);
EXPORT_C void free_dops_handle(dops_handle_t *);
EXPORT_C int dops_add(dops_handle_t *opaque, const int a, const int b);
EXPORT_C int dops_sub(dops_handle_t *opaque, const int a, const int b);
EXPORT_C int dops_get_add_count(dops_handle_t *dops_ptr);
EXPORT_C int dops_get_sub_count(dops_handle_t *dops_ptr);

#endif /* __WRAPPER_H__ */
