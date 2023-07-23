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
int partition(int A[], size_t size, size_t lo, size_t hi)
{

	long int pivot = A[hi];
	size_t j, i = lo - 1;

	j = hi + 1;
/*printf("pivot = %ld\n",pivot);*/
	while (1)
	{

		do {
			i = i + 1;
			/*printf(" *%ld: A[%ld]=%d < %ld\n", i,i,A[i],pivot);*/
		} while (i < hi && A[i] < pivot);

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
void quicksort(int A[], size_t size, size_t lo, size_t hi)
{
	size_t p;

	if (lo < hi)
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
	if (array == NULL || size <= 1)
	return;
	quicksort(array, size, 0, size - 1);
}
