#include <stdio.h>

/**
 * main - a function that prints the file name it
 * was compiled from.
 *
 * Return: always 0 (success)
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}

