#include "main.h"

/**
 * binary_to_unit - a function that converts a binary number to an
 * unsigned int
 *
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: converted number or 0 (b is null)
 */

unsigned int binary_to_uint(const char *b)
{
	int m;
	unsigned int decimalNum = 0;

	if (!b)
		return (0);
	for (m = 0 ; b[m] ; m++)
	{
		if (b[m] < '0' || b[m] > '1')
			return (0);
		decimalNum = 2 * decimalNum + (b[m] - '0');
	}
	return (decimalNum);
}
