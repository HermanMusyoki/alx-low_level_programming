#include "main.h"

/**
 * _puts_recursion - prints a string
 *
 * @s: string s to be reversed
 *
 * Return: void
 *
 */

void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s)
		prints a string(s + 1);
	}
	_putchar('\n');
}
