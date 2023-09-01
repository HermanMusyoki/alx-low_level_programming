#include "main.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * string_is_number - function to check digit in a string
 *
 * @s: string s to be checked
 *
 * Return: 0 (success) and 1 otherwise
 *
 */
int string_is_number(char *s)
{
	unsigned int  j = 0;

	while (j < strlen(s))
	{
		if (!isdigit(s[j]))
			return (0);
	j++;
	}
	return (1);

}


/**
 * main - program to add 2 positive numbers
 *
 * @argc: number of arguments passed
 * @argv: array of program arguments
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	int m;
	int sum = 0;
	int to_integer;

	for (m = 1 ; m < argc ; m++)
	{
		if (string_is_number(argv[m]))
		{
			to_integer = atoi(argv[m]);

			sum += to_integer;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);

	return (0);
}
