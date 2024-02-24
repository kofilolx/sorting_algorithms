#include "sort.h"
#include <stdio.h>

/**
 * shell_swap - swaps two elements.
 * @array: array of elements
 * @a: 0th index
 * @b: ith index
 */
void shell_swap(int *array, int a, int b)
{
	int tmp;

	if (array[a] != array[b])
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
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

	hld = 0;
	if (array == NULL || size < 2)
		return;

	while (hld <= size / 3)
		hld = hld * 3 + 1;

	while (hld >= 1)
	{
		for (idx = hld; idx < size; idx++)
		{
			for (jmp = idx; jmp >= hld && array[jmp] < array[jmp - hld]; jmp -= hld)
			{
				shell_swap(array, jmp, jmp - hld);
			}
		}
		hld /= 3;
		print_array(array, size);
	}
}
