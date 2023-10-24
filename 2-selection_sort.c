#include "sort.h"

/**
 * selection_sort - Sorting integer array with selection sort
 * @array: Address of array
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, x, temp, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;

		for (x = 0; x < size; x++)
		{
			printf("%d", array[x]);
			if (x < size - 1)
				printf(", ");
		}
		printf("\n");
	}
}
