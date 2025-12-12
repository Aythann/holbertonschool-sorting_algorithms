#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using Bubble sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t first, second;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (first = 0; first < size - 1; first++)
	{
		swapped = 0;

		for (second = 0; second < size - first - 1; second++)
		{
			if (array[second] > array[second + 1])
			{
				temp = array[second];
				array[second] = array[second + 1];
				array[second + 1] = temp;

				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
