#include "main.h"
#include <stdio.h>

/**
 * print_array - a function to print n elements of an array
 *
 * @a: the array to select the elements to print
 * @n: number of elements to be printed
 *
 * Return: void
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0 ; i < n ; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf("\n");
}
