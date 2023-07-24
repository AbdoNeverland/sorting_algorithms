#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <limits.h>
void swapp( int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {INT_MAX, 48, 99, 71, INT_MIN, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);
    int a =INT_MIN,b=INT_MAX;
printf("min=%d  max=%d\n", a,b);
swapp(&a,&b);
printf("min=%d  max=%d\n", a,b);
    print_array(array, n);
    printf("\n");
    quick_sort_hoare(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
