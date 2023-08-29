#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 *
 * @s: pointer to pointer of string s
 * @to: character to be set
 *
 * Return: void
 */

void set_string(char **s, char *to)
{
	*s = to;
}
