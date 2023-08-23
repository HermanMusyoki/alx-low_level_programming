#include "main.h"

/**
 * leet - a function that encodes a string into 1337
 *
 * @n: - pointer string
 *
 * Return: string n
 */


char *leet(char *n)
{
	int i, j;

	char leet_letters[] = "aAeEoOtTlL";
	char leet_numbers[] = "4433007711";

	for (i = 0 ; n[i] != '\0' ; i++)
	{
		for (j = 0 ; j < 10 ; j++)
		{
			if (leet_letters[j] == n[i])
				n[i] = leet_numbers[j];
		}
	}
	return (n);

}

