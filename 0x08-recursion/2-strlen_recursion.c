#include "main.h"

/**
 * _strlen_recursion - the function to find string length
 *
 * @s: string s to find the length
 *
 * Return: string length
 */
int _strlen_recursion(char *s)
{
	int stringLength = 0;

	if (*s != 0)
	{
		stringLength++;
		stringLength += _strlen_recursion(s + 1);
	}

	return (stringLength);
}
