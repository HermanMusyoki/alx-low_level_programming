#include "main.h"

/**
 * puts_half - a function that prints second half of a string
 *
 * @str: the string to be half printed
 *
 * Return: void
 */

void puts_half(char *str)
{
	int i, n;
	int stringCount = 0;

	for (i = 0 ; str[i] != '\0' ; i++)
		stringCount++;
	n = (stringCount - 1) / 2;
	for (i = n + 1 ; str[i] != '\0' ; i++)
		_putchar(str[i]);
	_putchar('\n');
}
