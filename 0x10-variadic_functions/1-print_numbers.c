#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - a function that prints numbers
 *
 * @separator: a string to be printed between numbers
 * @n: number of integers passed to the function
 *
 * Return: print numbers
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers_to_print;
	unsigned int m;

	va_start(numbers_to_print, n);

	for (m = 0 ; m < n ; m++)
	{
		printf("%d", va_arg(numbers_to_print, int));

		if (m != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(numbers_to_print);
}
