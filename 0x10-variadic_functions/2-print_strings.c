#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - a function that prints strings
 *
 * @separator: the string to be printed between the strings
 * @n: the number of strings passed to the function
 *
 * Return: print strings
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings_to_print;
	unsigned int m;
	char *string;

	va_start(strings_to_print, n);

	for (m = 0 ; m < n ; m++)
	{
		string = va_arg(strings_to_print, char *);

		if (string == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", string);
		}
		if (m != (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	printf("\n");

	va_end(strings_to_print);

}
