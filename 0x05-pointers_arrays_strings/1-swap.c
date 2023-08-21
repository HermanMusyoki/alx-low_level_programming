#include "main.h"

/**
 * swap_int - a function that swaps the values of 2 integers
 *
 * @a: pointer a for first value
 * @b: pointer b for the second value
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}
