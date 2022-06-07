#include "dummy.hpp"

#include <stdlib.h>
#include "wrapper.h"

// SPDX-License-Identifier : BSD-3-Clause-Attribution

int dummy_ops::add(const int &a, const int &b)
{
	inc_add_ops_count();
	return (a+b);
}

int dummy_ops::sub(const int &a, const int &b)
{
	inc_sub_ops_count();
	return (a-b);
}

void dummy_ops::reset_ops_count(void)
{
	add_ops_count = 0;
	sub_ops_count = 0;
}

void create_dops_handle(dops_handle_t **ref)
{
	if (!ref)
		return;

	dops_handle_t *opaque;
	opaque = (dops_handle_t *)calloc(1, sizeof(*opaque));
	dummy_ops *dops_obj = new dummy_ops;
	opaque->dops_ptr = dops_obj;
	*ref = opaque;
}

void free_dops_handle(dops_handle_t *opaque)
{
	if (!opaque)
		return;

	dummy_ops *obj = static_cast<dummy_ops *>(opaque->dops_ptr);
	delete obj;
	free(opaque);
}

int dops_add(dops_handle_t *opaque, const int a, const int b)
{
	if (!opaque)
		return 0;

	dummy_ops *obj = static_cast<dummy_ops *>(opaque->dops_ptr);
	return obj->add(a,b);
}

int dops_sub(dops_handle_t *opaque, const int a, const int b)
{
	if (!opaque)
		return 0;

	dummy_ops *obj = static_cast<dummy_ops *>(opaque->dops_ptr);
	return obj->sub(a,b);
}

int dops_get_add_count(dops_handle_t *opaque)
{
	if (!opaque)
		return 0;

	dummy_ops *obj = static_cast<dummy_ops *>(opaque->dops_ptr);
	return obj->get_add_ops_count();
}

int dops_get_sub_count(dops_handle_t *opaque)
{
	if (!opaque)
		return 0;

	dummy_ops *obj = static_cast<dummy_ops *>(opaque->dops_ptr);
	return obj->get_sub_ops_count();
}
