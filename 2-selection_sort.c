#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array
 * @size: The size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, jmp, min_idx;
	int tmp;

	while (!array || !size)
		return;

	/* move boundary of unsorted array index by index */
	for (idx = 0; idx < size - 1; idx++)
	{
		/* find minimum element in array */
		min_idx = idx;
		for (jmp = idx + 1; jmp < size; jmp++)
		{
			if (array[jmp] < array[min_idx])
			{
				min_idx = jmp;
			}
		}
		if (min_idx != idx)
		{
			tmp = array[idx];
			array[idx] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
