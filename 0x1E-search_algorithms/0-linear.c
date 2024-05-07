#include "search_algos.h"

/**
 * linear_search -  Function that searches for a value in an array
 *                 of integers using linear search.
 * @array: A pointer to the first element of the array to search the value
 * @size: The number of elements in the array
 * @value: The value to search for in the array
 *
 * Return: -1 (value not present or null array) or first index of the value
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);

		if (array[i] == value)


			return (i);
	}

	return (-1);
}
