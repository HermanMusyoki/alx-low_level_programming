#include "main.h"

/**
 * reverse_array - a function to reverse array of integers
 *
 * @a: array to be reversed
 * @n: number of elements of the array
 *
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int index, m;

	n = n - 1;

	for (m = 0 ; m <= n ; m++)
	{
		index = a[m];
		a[m++] = a[n];
		a[n--] = index;
	}
}
