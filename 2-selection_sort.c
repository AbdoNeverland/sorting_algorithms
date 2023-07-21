#include "sort.h"

/**
 * selection_sort - selection sort algo
 * @array: The array
 * @size: Number
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, t, c;
	int m;

	for (i = 0; i < size; i++)
	{
		m = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[m])
			{
				m = j;
			}
		}
		if (m != i)
		{
			t = array[m];
			array[m] = array[i];
			array[i] = t;
			print_array(array, size);
		}
	}
}
