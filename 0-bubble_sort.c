#include "sort.h"

/**
 * bubble_sort - Sorting a list
 * @array: Interger array to be sorted
 * @size: Size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, x, temp;
	int swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
			}
			if (swap == 1)
			{
				for (x = 0; x < size; x++)
				{
					if (array[x] == array[size - 1])
						printf("%d", array[x]);
					else
						printf("%d, ", array[x]);
				}
				printf("\n");	
			}
			swap = 0;
		}
	}
}
