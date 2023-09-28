#include "main.h"

/**
 * clear_bit - a function that sets value of a bit
 * to 0 at a given index
 *
 * @n: the number to be set
 * @index: index position to set bit to 0
 *
 * Return: 1 (success) or -1 (fail)
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);

	return (1);
}
