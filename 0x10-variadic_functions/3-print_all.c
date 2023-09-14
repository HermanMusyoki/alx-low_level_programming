#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - a function that prints anything passed to it
 *
 * @format: a list of arguments passed to the function
 *
 * Return: print all arguments passed
 */
void print_all(const char * const format, ...)
{
	char *string, *separator = "";
	int m = 0;

	va_list ap;

	va_start(ap, format);
	if (format)
	{
		while (format[m])
		{
			switch (format[m])
			{
				case 'c':
					printf("%s%c", separator, va_arg(ap, int));
					break;
				case 'i':
					printf("%s%d", separator, va_arg(ap, int));
					break;
				case 'f':
					printf("%s%f", separator, va_arg(ap, double));
					break;
				case 's':
					string = va_arg(ap, char *);
					if (!string)
						string = "(nil)";
					printf("%s%s", separator, string);
					break;
				default:
					m++;
					continue;
			}
			separator = ", ";
			m++;
		}
	}
	printf("\n");
	va_end(ap);

}
