#include "main.h"
#include <stdio.h>
/**
 * _string_to_integer - the function changes a string to integer
 * @s: string s to be changed
 *
 * Return: integer result of the string
 */

int _string_to_integer(char *s)
{
	int m = 0;
	int n = 0;
	int length = 0;
	int value = 0;
	int number = 0;
	int i = 0;

	while (s[length] != '\0')
		length++;
	for (; i < length && value == 0 ; i++)
	{
		if (s[i] == '-')
			++m;

		if (s[i] >= '0' && s[i] <= '9')
		{
			number = s[i] - '0';
			if (m % 2)
				number = -number;
			n = n * 10 + number;
			value = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			value = 0;
		}

	}
	if (value == 0)
		return (0);
	return (n);

}

/**
 * main - prints product of two numbers
 *
 * @argc: number of arguments passed
 * @argv: array of program arguments
 *
 * Return: always 0 (success) and 1 otherwise
 */

int main(int argc, char *argv[])
{
	int firstNumber, secondNumber, result;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}

	firstNumber = _string_to_integer(argv[1]);
	secondNumber = _string_to_integer(argv[2]);
	result = firstNumber * secondNumber;
	printf("%d\n", result);

	return (0);
}
