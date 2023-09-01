#include "main.h"
#include <stdio.h>

/**
 * main -  prints the number of arguments passed
 *
 * @argc: number of arguments passed to the program
 * @argv: array of program arguments
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
/*a code to ignore argv to avoid compile error*/
(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
