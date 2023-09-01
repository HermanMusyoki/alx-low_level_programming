#include "main.h"
#include <stdio.h>

/**
 * main - prints all the arguments passed into it
 *
 * @argc: number of arguments passed
 * @argv: array of program arguments
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	int m;

	for (m = 0 ; m < argc ; m++)
		printf("%s\n", argv[m]);

	return (0);
}
