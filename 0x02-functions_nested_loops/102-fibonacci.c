#include <stdio.h>

/**
 * main - a function that prints the first 50 Fibonacci numbers
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int num1 = 1;
	int num2 = 2;
	int n;
	int nextNum;

	printf("%d, ", num1);

	for (n = 1 ; n < 50 ; n++)
	{
		printf("%d", num2);
		nextNum = num1 + num2;
		num1 = num2;
		num2 = nextNum;
		if (n != 49)
			printf(", ");
	}

	printf("\n");
	return (0);
}
