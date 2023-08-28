#include "main.h"

/**
 * print_diagsums - print sum of 2 diagonals os a square matrix of integers
 *
 * @a: array to be printed
 * @size: size of the square
 *
 * Return: void
 */

void print_diagsums(int *a, int size)
{
	int i, firstSum, secondSum;

	firstSum = 0;
	secondSum = 0;
	i = 0;

	while (i < size)
	{
		firstSum = firstSum + a[i * size + i];
	i++;
	}

	i = size - 1;

	while (i >= 0)
	{
		secondSum += a[i * size + (size - i - 1)];
	i--;
	}

	printf("%d, %d\n", firstSum, secondSum);
}
