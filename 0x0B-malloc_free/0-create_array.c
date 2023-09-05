#include "main.h"

/**
 * create_array - function that creates an array of chars with
 * initialization with a specific char
 *
 * @size: size of the array
 * @c: characters in the array
 *
 * Return: array pointer (success) and NUll (fail)
 */

char *create_array(unsigned int size, char c)
{
	unsigned int m;
	char *array;

	if (size == 0)
		return (NULL);
	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	m = 0;

	while (m < size)
	{
		array[m] = c;
		m++;
	}

	return (array);
}

