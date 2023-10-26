#include "main.h"

/**
 * get_endianness - a function that chechs the endianness
 *
 * Return: 0 (big) 0r 1 (little)
 */

int get_endianness(void)
{
	unsigned int m = 1;
	char *s = (char *) &m;

	return (*s);
}

