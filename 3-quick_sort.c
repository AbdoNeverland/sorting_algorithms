#include "sort.h"

/**
 * swap - sawp
 * @array: The array
 * @size: Number
 * @a: first
 * @b: second
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
	print_array(array, size);
}

/**
 * partition - partition
 * @A: The array
 * @size: Number
 * @lo: minimum
 * @hi: max
 * Return: int
 */
int partition(int A[], size_t size, int lo, int hi)
{
	int pivot = A[hi];

	int j, i = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (A[j] <= pivot)
		{
			i = i + 1;
			if (i != j)
				swap(A, size, &A[i], &A[j]);
		}
	}

	i = i + 1;
	if (i != hi)
		swap(A, size, &A[i], &A[hi]);
	return (i);
}

/**
 * quicksort_partition -quicksort partition
 *
 * @A: The array
 * @size: Number
 * @lo: minimum
 * @hi: max
 */
void quicksort_partition(int *A, size_t size, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(A, size, lo, hi);

	quicksort_partition(A, size, lo, p - 1);
	quicksort_partition(A, size, p + 1, hi);
}

/**
 * quick_sort - quick sort
 *
 * @array: The array
 * @size: Number
 */
void quick_sort(int *array, size_t size)
{
	quicksort_partition(array, size, 0, size - 1);
}
