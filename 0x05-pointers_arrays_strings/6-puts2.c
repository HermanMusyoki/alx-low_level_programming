#include "main.h"

/**
 * puts2 - a function that prints every other character os a string
 * from the first character
 *
 * @str: the string to be printed
 *
 * Return: void
 */

void puts2(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (i % 2 == 0)
			_putchar(str[i]);
	}
	_putchar('\n');

}
