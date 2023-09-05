#include "main.h"

/**
 * _strdup - function returns apointer to a copy of the
 * given string str
 *
 * @str: pointer to the given string
 *
 * Return: pointer str (success) and NULL (fail)
 */

char *_strdup(char *str)
{
	char *duplicate;
	int strlen = 0;
	int m = 0;

	if (str == NULL)
		return (NULL);

	while (str[m] != '\0')
	{
		strlen++;
		m++;
	}

	duplicate = malloc((sizeof(char) * strlen) + 1);

	if (duplicate == NULL)
		return (NULL);

	for (m = 0 ; str[m] != '\0' ; m++)
	{
		duplicate[m] = str[m];
	}

	return (duplicate);
}
