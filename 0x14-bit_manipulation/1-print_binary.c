#include "main.h"

/**
 * print_binary - a function that prints the binary
 * representation of a number
 *
 * @n: the number to convert to binary form
 *
 * Return: binary representation of the given number
 */
void print_binary(unsigned long int n)
{
	int m, counter = 0;
	unsigned long int num;

	for (m = 63 ; m >= 0 ; m--)
	{
		num = n >> m;

		if (num & 1)
		{
			_putchar('1');
			counter++;
		}
		else if (counter)
			_putchar('0');

	}
	if (!counter)
		_putchar('0');
}

