#include "wrapper.h"

#include <stdio.h>
#include <errno.h>

// SPDX-License-Identifier : BSD-3-Clause-Attribution

int main(void)
{
	dops_handle_t *dh = NULL;
	dops_handle_t **ref = &dh;
	create_dops_handle(ref);
	if (!dh || !dh->dops_ptr) {
		printf("Error: Unable to create_dops_handle\n");
		return -ENOMEM;
	}
	int i, j;

	for (i = 1, j = 11; i <= 10 && j <=20; i++, j++) {
		printf("%d + %d = %d\t", j, i, dops_add(dh, j, i));
		printf("%d - %d = %d\n", j, i, dops_sub(dh, j, i));
	}
	printf(" add ops performed = %d\n", dops_get_add_count(dh));
	printf(" sub ops performed = %d\n", dops_get_sub_count(dh));


	free_dops_handle(dh);
	return 0;
}
