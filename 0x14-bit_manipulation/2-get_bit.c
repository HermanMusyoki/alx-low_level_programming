#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at
 * a given index
 *
 * @n: the number to be eximined
 * @index: index point to return the bit value
 *
 * Return: value at given index or -1 (fail)
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int value;

	if (index > 63)
		return (-1);
	value = (n >> index) & 1;

	return (value);
}
