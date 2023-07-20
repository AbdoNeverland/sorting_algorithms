#include "sort.h"


/**
 * bubble_sort - sort array using bubble algo
 * @array: array
 * @size: elm's number
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, t;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
				print_array(array, size);
			}
		}
	}
}
