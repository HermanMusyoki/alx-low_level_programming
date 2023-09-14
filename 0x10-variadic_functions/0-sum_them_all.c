#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - a function that returns the sum of
 * all its parameters.
 *
 * @n: the numbers of parameters passed to the function
 * @...: the variable of unamed paraments to find sum
 *
 * Return: sum of parameters and 0 (n == 0)
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int index, sum = 0;

	va_start(ap, n);

	for (index = 0 ; index < n ; index++)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);

	return (sum);
}
