#include "function_pointers.h"

/**
 * print_name - a function that prints a name
 *
 * @name: pointer to the string name
 * @f: pointer to the function
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
