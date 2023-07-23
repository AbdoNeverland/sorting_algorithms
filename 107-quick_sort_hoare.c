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
 * @lo: first
 * @hi: second
 * Return: int
 */
int partition(int A[], size_t size, int lo, int hi)
{

	int pivot = A[hi];
	int j, i = lo - 1;

	j = hi + 1;

	while (1)
	{

		do {
			i = i + 1;
		} while (A[i] < pivot);

		do {
			j = j - 1;
		} while (A[j] > pivot);

		if (i > j)
			return (j);
		if (A[i] != A[j])
		swap(A, size, &A[i], &A[j]);
	}
}

/**
 * quicksort - quicksort
 * @A: The array
 * @size: Number
 * @lo: first
 * @hi: second
 */
void quicksort(int A[], size_t size, int lo, int hi)
{
	int p;

	if (lo >= 0 && hi >= 0 && lo < hi)
	{
		p = partition(A, size, lo, hi);
		quicksort(A, size, lo, p);
		quicksort(A, size, p + 1, hi);
	}
}
/**
 * quick_sort_hoare - quick sort_hoare
 * @array: array
 * @size: elm's number
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
	return;
	quicksort(array, size, 0, size - 1);
}
