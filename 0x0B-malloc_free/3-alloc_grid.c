#include "main.h"

/**
 * alloc_grid - function that returns a pointer to 2 dimensional
 * arry of integers
 *
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to array and NULL (fail)
 */
int **alloc_grid(int width, int height)
{
	int m, n;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	m = 0;

	while (m < height)
	{
		grid[m] = malloc(sizeof(int) * width);

		if (grid[m] == NULL)
		{
			free(grid);
			for (n = 0 ; n <= height ; n++)
				free(grid[n]);
			return (NULL);
		}
		for (n = 0; n < width ; n++)
			grid[m][n] = 0;
		m++;
	}
	return (grid);
}
