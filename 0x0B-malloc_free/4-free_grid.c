#include "main.h"

/**
 * free_grid - frees the memory for 2 dimensional grid
 *
 * @grid: the grid array to be freed from memory
 * @height: the height of the grid
 *
 * Return: always (0)
 */


void free_grid(int **grid, int height)
{
	int m = 0;

	while (m < height)
	{
		free(grid[m]);
		m++;
	}

	free(grid);

}
