#include "main.h"

/**
 * print_rev - a function that prints a string in reverse
 *
 * @s: - the string to be reversed
 *
 * Return: void
 */

void print_rev(char *s)
{
	int i;
	int stringCount = 0;

	for (i = 0; s[i] != '\0' ; i++)
		stringCount++;
	for (i = stringCount - 1 ; i >= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
}
