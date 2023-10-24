#include "sort.h"

/**
 * quick_sort - Sorts array in ascending order
 * @array: Address of an array
 * @size: Size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size > 0)
		quick_sort_helper(array, 0, size - 1);
}

/**
 * swap - Swaps two integer values.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Performs Lomuto partitioning of an array.
 * @array: Pointer to the array.
 * @low: The starting inex of the partition.
 * @high: The ending index of the partition.
 * Return: The index where the pivot element is placed after partitioning.
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(@array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_helper - Recursively sorts an array using Quick Sort.
 * @array: Pointer to the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * Return: void.
 */

void quick_sort_helper(int *array, int low, int high)
{
	int partition_idx, i;

	if (low < high)
	{
		partition_idx = lomuto_partition(array, low, high);

		for (i = 0; i < high + 1; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
		}
		printf("\n");

		quick_sort_helper(array, low, partition_idx - 1);
		quick_sort_helper(array, partition_idx + 1, high);
	}
}
