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
static int partition(int *array, int little, int bigger, size_t size)
{
	int pivot = array[bigger];
	int i = little - 1;
	int j;

	for (j = little; j < bigger; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != bigger)
	{
		swap_int(&array[i + 1], &array[bigger]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_rec - Recursively sorts partitions of the array
 * @array: Array to be sorted
 * @little: Starting index of the partition
 * @bigger: Ending index of the partition
 * @size: Size of the array
 */
static void quick_sort_rec(int *array, int little, int bigger, size_t size)
{
	int pivot_index;

	if (little < bigger)
	{
		pivot_index = partition(array, little, bigger, size);
		quick_sort_rec(array, little, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, bigger, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
