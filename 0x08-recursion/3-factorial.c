#include "main.h"

/**
 * factorial - function that finds factorial of a number
 *
 * @n: the number to get facrorial
 *
 * Return: factorial result
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}

