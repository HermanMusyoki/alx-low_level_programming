#include "main.h"
/**
 * cap_string - function to capitalize all words of a string
 *
 * @n: the string pointer
 *
 * Return: string n
 */

char *cap_string(char *n)
{
	int i;

	for (i = 0; n[i] != '\0' ; i++)
	{
		if (n[0] >= 97 && n[0] <= 122)
			n[0] = n[0] - 32;
		if (n[i] == ' ' || n[i] == ';' || n[i] == '.' || n[i] == ',' || n[i] == '\t'
				|| n[i] == '!' || n[i] == '\n' || n[i] == '?' || n[i] == '{' ||
				n[i] == '}' || n[i] == '(' || n[i] == ')' || n[i] == '"')
		{
			if (n[i + 1] >= 97 && n[i + 1] <= 122)
				n[i + 1] = n[i + 1] - 32;
		}
	}
	return (n);

}
