#include <stdio.h>
#include <stdlib.h>


/** main - a function to print opcodes of its own
 * main function
 * @argc: the number of arguments passed to the function
 * @argv: array of arguments to the function
 *
 * Return: always 0 (success)
 */
int main(int argc, char *argv[])
{
	int number_of_bytes, m;
	char *array;

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

	array = (char *)main;

	m = 0;
	while (m < number_of_bytes)
	{
		if (m == number_of_bytes - 1)
		{
			printf("%02hhx\n", array[m]);
			break;
		}
		printf("%02hhx", array[m]);
		m++;
	}
	return (0);

}
