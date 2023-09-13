#include "function_pointers.h"

/**
 * int_index - a function that searches for an integer
 *
 * @array:  array to be searched
 * @size: number of array elements
 * @cmp: a pointer to the function used to compare values
 *
 * Return: 0 (success) and -1 (size <= 0 or empty array)
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int m;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	m = 0;
	while (m < size)
	{
		if (cmp(array[m]))
			return (m);
		m++;
	}
	return (-1);
}
