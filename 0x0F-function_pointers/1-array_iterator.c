#include "function_pointers.h"

/**
 * array_iterator - a function that executes a func given as a
 * parameter on each element of an array
 *
 * @array: array of elements
 * @size: size of the array
 * @action: pointer to the function
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int m;

	if (array == NULL || action == NULL)
		return;
	m = 0;
	while (m < size)
	{
		action(array[m]);
		m++;
	}
}
