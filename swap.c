#include "sort.h"

/*
 *
 *
 *
 *
 */

void swap_sort(int *pv, int *nxt)
{
	int tmp;

	tmp = pv;
	pv = nxt;
	nxt = tmp;
}
