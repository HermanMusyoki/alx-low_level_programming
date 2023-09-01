#include "main.h"
#include <stdio.h>

/**
 * main - prints the program name
 * @argc: number of arguments passed to the program
 * @argv: array of the program arguments
 *
 * Return: always 0 (success)
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
