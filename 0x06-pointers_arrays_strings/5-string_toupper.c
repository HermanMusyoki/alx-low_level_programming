 #include "main.h"

/**
 * string_toupper - a function to change lowercase letters to upper
 * @n: pointer to the string to be checked
 * Return: string n
 */

char *string_toupper(char *n)
{
	int i;

	for (i = 0 ; n[i] != '\0' ; i++)
	{
		if (n[i] >= 97 && n[i] <= 122)
			n[i] = n[i] - 32;
	}
	return (n);
}
