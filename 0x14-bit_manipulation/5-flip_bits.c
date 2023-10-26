#include "main.h"

/**
 * flip_bits - a function that returns the number of bits
 *  to flip fron one number to another
 *
 *  @n: first number to get bits to flip
 *  @m: second number to flip bits to
 *
 *  Return: numbers of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int p, counter = 0;
	unsigned long int number;
	unsigned long int value = n ^ m;

	for (p = 63 ; p >= 0 ; p--)
	{
		number = value >> p;
		if (number & 1)
		{
			counter++;
		}
	}

	return (counter);
}

