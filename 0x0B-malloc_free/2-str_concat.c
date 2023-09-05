#include "main.h"

/**
 * str_concat - a function that joins two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer joined s1 + s2 and Null otherwise
 */

char *str_concat(char *s1, char *s2)
{
	int s1_length = 0;
	int s2_length = 0;
	int combined_length;
	int m;
	char *concat_str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (m = 0 ; s1[m] != '\0' ; m++)
		s1_length++;
	for (m = 0 ; s2[m] != '\0' ; m++)
		s2_length++;


	combined_length = s1_length + s2_length;

	concat_str = malloc((sizeof(char) * combined_length) + 1);

	if (concat_str == NULL)
		return (NULL);
	for (m = 0 ; s1[m] != '\0' ; m++)
		concat_str[m] = s1[m];

	m = 0;

	while (s2[m] != '\0')
	{
		concat_str[s1_length + m] = s2[m];
		m++;
	}


	return (concat_str);
}
