#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * argstostr - a function that concannates all the arguments
 * of the program
 *
 * @ac: number of arguments passed in a program
 * @av: arrays of of program arguments
 *
 * Return: pointer to new string and NULL (fail)
 */


char *argstostr(int ac, char **av)
{

	int total_length = 0;
	int i, j, m;
	char *result;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			total_length++;
		}
		total_length++;
	}
	result = malloc(sizeof(char) * (total_length + 1));
	if (result == NULL)
	{
		return (NULL);
	}

	m = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[m++] = av[i][j];
		}
		if (result[m] == '\0')
		{
			result[m++] = '\n';
		}
	}

	result[m] = '\0';
	return (result);
}

