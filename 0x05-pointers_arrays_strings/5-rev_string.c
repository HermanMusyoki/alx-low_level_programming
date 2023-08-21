#include "main.h"

/**
 * rev_string - a function that reverses a string
 *
 * @s: the string value to be reversed
 *
 * Return: void
 */

void rev_string(char *s)
{
	int i;
	int stringCount = 0;

	for (i = 0 ; s[i] != '\0' ; i++)
		stringCount++;
	for (i = 0 ; i < stringCount / 2 ; i++)
	{
		char c;

		c = s[i];
		s[i] = s[(stringCount - 1) - i];
		s[(stringCount - 1) - i] = c;
	}
}
