#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int A[] = {48, 99, 71, 13, 52, 96, 73, 86, 7, INT_MAX};
	size_t n = sizeof(A) / sizeof(A[0]);
	long int pivot = A[n-1];
	size_t i = 0 - 1;

	do
	{
		i = i + 1;
		printf("*%ld: A[%ld]=%d < %ld\n", i, i, A[i], pivot);
	} while (A[i] < pivot);
	return (0);
}
