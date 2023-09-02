#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make
 * change for an amount of money
 *
 * @argc: number of arguments passed to a program
 * @argv: array of program arguments
 *
 * Return: 0 (success) and 1 otherwise
 */

int main(int argc, char *argv[])
{
	int number_of_coins[] = {25, 10, 5, 2, 1};
	int digit;
	int m = 0;
	int value = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	digit = atoi(argv[1]);

	if (digit < 0)
	{
		printf("0\n");
		return (0);
	}
	while (m < 5 && digit >= 0)
	{
		while (digit >= number_of_coins[m])
		{
			value++;
			digit -= number_of_coins[m];
		}
	m++;
	}
	printf("%d\n", value);
	return (0);
}
