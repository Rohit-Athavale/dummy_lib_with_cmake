#ifndef __WRAPPER_H__
#define __WRAPPER_H__

// SPDX-License-Identifier : BSD-3-Clause-Attribution

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64)
#ifdef DUMMYL_EXPORTS
#define DUMMYL_API __declspec(dllexport)
#else
#define DUMMYL_API __declspec(dllimport)
#endif /* DUMMYL_EXPORTS  */
#endif /* _WIN32, WIN32 or _WIN64 */

#if defined(__linux__)
#define DUMMYL_API
#endif /* __linux__ */

#ifdef __cplusplus
	#define EXPORT_C extern "C"
#else
	#define EXPORT_C
#endif

EXPORT_C DUMMYL_API typedef struct dops_handle
{
	void *dops_ptr;
} dops_handle_t;

EXPORT_C DUMMYL_API void create_dops_handle(dops_handle_t **);
EXPORT_C DUMMYL_API void free_dops_handle(dops_handle_t *);
EXPORT_C DUMMYL_API int dops_add(dops_handle_t *opaque, const int a, const int b);
EXPORT_C DUMMYL_API int dops_sub(dops_handle_t *opaque, const int a, const int b);
EXPORT_C DUMMYL_API int dops_get_add_count(dops_handle_t *dops_ptr);
EXPORT_C DUMMYL_API int dops_get_sub_count(dops_handle_t *dops_ptr);

#endif /* __WRAPPER_H__ */
