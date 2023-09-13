#include <stdio.h>
#include <stdlib.h>

/**
 * main - a function to print opcodes of its own
 * main function
 * @argc: the number of arguments passed to the function
 * @argv: array of arguments to the function
 *
 * Return: always 0 (success)
 */
int main(int argc, char *argv[])
{
	int number_of_bytes, m;
	int (*func_ptr)(int, char **) = main;
	unsigned char print_opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	number_of_bytes = atoi(argv[1]);

	if (number_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (m = 0 ; m < number_of_bytes ; m++)
	{
		print_opcode = *(unsigned char *)func_ptr;
		printf("%.2x", print_opcode);

		if (m == number_of_bytes - 1)
			continue;
		printf(" ");

		func_ptr++;
	}
	printf("\n");
	return (0);

}
