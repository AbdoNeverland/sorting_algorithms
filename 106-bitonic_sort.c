#include "sort.h"

/**
 * swap - sawp
 * @array: The array
 * @size: Number
 * @a: first
 * @b: second
 */
void swap(int *array, size_t size, int i, int j)
{
	int t;

printf("swaping %d %d \n", i, j);
	t = array[i];
	array[i] = array[j];
	array[j] = t;
	
	print_array(array, size);
}

/**
 * bitonic_sort - bitonic sort
 * @array: array
 * @size: elm's number
 */
void bitonic_sort(int *array, size_t size)
{
	int i, j, k, l, n = size;
	for (k = 2; k <= n; k *= 2)
	{
		for (j = k / 2; j > 0; j /= 2)
		{
			for (i = 0; i < n; i++)
			{
				l = i ^ j;
				if (l > i)
				{
					if ((( (i & k) == 0) && (array[i] > array[l])) ||
						(((i&k) != 0) && (array[i] < array[l])))
						swap(array, size, i, l);
				}
			}
		}
	}
}
