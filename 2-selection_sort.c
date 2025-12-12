#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t first, second, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (first = 0; first < size - 1; first++)
	{
		min_index = first;

		for (second = first + 1; second < size; second++)
		{
			if (array[second] < array[min_index])
				min_index = second;
		}

		if (min_index != first)
		{
			temp = array[first];
			array[first] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
