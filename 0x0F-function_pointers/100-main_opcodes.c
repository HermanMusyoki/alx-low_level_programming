#include <stdio.h>
#include <stdlib.h>
/**
 * print_opcodes - prints the opcodes of a function
 * @number_of_bytes: the number of bytes to print
 * @function_ptr: pointer to the function to print its bytes
 * Return: nothing
 */
void print_opcodes(int number_of_bytes, void (*function_ptr)(int, char *[]))
{
	int m;
	unsigned char *func_ptr = (unsigned char *)function_ptr;

	m = 0;
	while (m < number_of_bytes)
	{
		printf("%02x", func_ptr[m]);
		if ((m + 1) % 2 == 0)
		{
			printf(" ");
		}
		m++;
	}
	printf("\n");
}

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
	int number_of_bytes;


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

	print_opcodes(number_of_bytes, (void(*)(int, char *[]))main);

	return (0);

}
