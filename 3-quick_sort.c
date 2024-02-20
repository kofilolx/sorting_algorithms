#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array.
 * @array: The array to modify.
 * @left: The index of the left elements.
 * @right: The index of the right elements.
 * size_t implemented (elements)
 */
void swap_elements(int *array, size_t left, size_t right)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
	}
}

/**
 * sort_lomuto - Sorts a sub-array using the Quick sort algorithm
 * with Lomuto's partition scheme.
 * This function sorts a sub-array of integers from 'low' to 'high'
 * within the given 'array' using the Quick Sort algorithm with Lomuto's
 * partition scheme. It rearranges the elements such that all elements
 * smaller than or equal to the pivot are placed before the pivot, and
 * all elements greater than the pivot are placed after the pivot
 * @array: Pointer to the integer array.
 * @low: Starting index of the sub-array.
 * @high: Ending index of the sub-array.
 * @size: Size of the array.
 */

void sort_lomuto(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t step, idx;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	step = low;
	for (idx = low; idx < high; idx++)
	{
		if (array[idx] <= pivot)
		{
			if (step != idx)
			{
				swap_elements(array, step, idx);
				print_array(array, size);
			}
			step++;
		}
	}
	if (step != high)
	{
		swap_elements(array, step, high);
		print_array(array, size);
	}
	if (step - low > 1)
		sort_lomuto(array, low, step - 1, size); /* Recursive call */
	if (high - step > 1)
		sort_lomuto(array, step + 1, high, size); /* Recursive call */
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		sort_lomuto(array, 0, size - 1, size);
	}
}
