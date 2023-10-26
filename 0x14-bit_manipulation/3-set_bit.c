#include "main.h"

/**
 * set_bit - a function that sets the value of a bit
 * to 1 at given index
 *
 * @n: number to set a bit
 * @index: index position where the bit is set to 1
 *
 * Return: 1 (success) or -1 (fail)
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
