#include "sort.h"
#include <stdio.h>

/**
 * shell_swap - swaps two elements.
 * @a: 0th index
 * @b: ith index
 */
void shell_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sort the list and print the changes
 * @array: The array to sort.
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t hld, idx, jmp;

	if (array == NULL || size < 2)
		return;

	for (hld = 1; hld < (size / 3);)
		hld = hld * 3 + 1;

	for (hld = 0; hld >= 1; hld /= 3)
	{
		for (idx = hld; idx < size; idx++)
		{
			jmp = idx;
			while (jmp >= hld && array[jmp - hld] > array[jmp])
			{
				shell_swap(array + jmp, array + (jmp - hld));
				jmp -= hld;
			}
		}
		print_array(array, size);
	}
}
