#include "main.h"
#define ERR_MSG "Error"
/**
 * check_digit - check for non digits in a string
 * @str: string to be checked
 * Return: 0 (success) and 1 (fail)
 */
int check_digit(char *str)
{
	int m;
	for (m = 0 ; str[m] != '\0' ; m++)
	{
		if(!isdigit(str[m]))
			return (0);
	}
	return (1);
}
/**
 * _strlength - a function to check for string length
 * @str: the string to check for length
 * Return: always 0 (success) and 1 (otherwise)
 */
int _strlength(char *str)
{
	int str_length = 0;

	while (str[str_length] != '\0')
	{
		str_length++;
	}
	return (str_length);
}
/**
 * errors - checks for errors
 */
void errors()
{
	printf("Error\n");
	exit(98);
}
/**
 * main - a function that multiplies two positive numbers
 * @argc: the number of arguments in a program
 * @argv: array of program arguments
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	char *str1, *str2;
	int num1, num2, strlen1, strlen2, total_length, m, base, *result, n = 0;

	str1 = argv[1]; 
	str2 = argv[2];
	if (argc != 3 || !check_digit(argv[1]) || !check_digit(argv[2]))
		errors();
	strlen1 = _strlength(str1);
	strlen2 = _strlength(str2);
	total_length = strlen1 + strlen2 + 1;
	result = malloc(sizeof(int) * total_length);
	if (!result)
		return (1);
	for (m = 0; m < total_length ; m++)
		result[m] = 0;
	for (strlen1 = strlen1 - 1; strlen1 >= 0 ; strlen1--)
	{
		num1 = str1[strlen1] - '0';
		base = 0;
		for (strlen2 = strlen2 - 1 ; strlen2 >= 0 ; strlen2--)
		{
			num2 = str2[strlen2] - '0';
			base += result[strlen1 + strlen2 + 1] + (num1 * num2);
			result[strlen1 + strlen2 + 1] = base % 10;
			base /= 10;
		}
		if (base > 0)
			result[strlen1 + strlen2 + 1] += base;
	}
	for (m = 0 ; m < total_length - 1 ; m++)
	{
		if (result[m])
			n = 1;
		if (n)
			_putchar(result[m] + '0');
	}
	if (!n)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
