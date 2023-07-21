#include "sort.h"

/**
 * selection_sort - selection sort
 *
 * @array: The array 
 * @size: Number
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, t;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[i])
			{
				t = array[i];
				array[i] = array[j];
				array[j] = t;
				print_array(array, size);
			}
		}
	}
}
