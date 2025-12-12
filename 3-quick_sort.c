#include "sort.h"

/**
 * swap_int - Swaps two integers in an array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
static void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array using Lomuto scheme
 * @array: Array to be partitioned
 * @little: Starting index of the partition
 * @bigger: Ending index of the partition (pivot index)
 * @size: Size of the array
 *
 * Return: Final index of the pivot
 */
static size_t partition(int *array, size_t little, size_t bigger, size_t size)
{
	int pivot;
	size_t i, j;

	pivot = array[bigger];
	i = little;

	for (j = little; j < bigger; j++)
	{
		if (array[j] < pivot)
		{
			swap_int(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}

	swap_int(&array[i], &array[bigger]);
	if (array[i] != array[bigger])
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_rec - Recursively sorts partitions of the array
 * @array: Array to be sorted
 * @little: Starting index of the partition
 * @bigger: Ending index of the partition
 * @size: Size of the array
 */
static void quick_sort_rec(int *array, size_t little, size_t bigger, size_t size)
{
	size_t pivot_index;

	if (little < bigger)
	{
		pivot_index = partition(array, little, bigger, size);

		if (pivot_index > 0)
			quick_sort_rec(array, little, pivot_index - 1, size);

		quick_sort_rec(array, pivot_index + 1, bigger, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto scheme)
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
