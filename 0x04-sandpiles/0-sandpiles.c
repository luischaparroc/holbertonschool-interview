#include "sandpiles.h"
#include <stdio.h>

/**
 * print_sandpile - prints input grid (or sandpile)
 * @grid: sandpile.
 * Return: no return.
 */
void print_sandpile(int grid[3][3])
{
	int i;
	int j;

	printf("=\n");

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * check_is_stable - function that checks if grid1
 * is stable and copies values to grid2
 * @grid1: first sandpile.
 * @grid2: second sandpile.
 * Return: 1 if grid1 is stable. Otherwise, 0.
 */
int check_is_stable(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;
	int stable;

	stable = 1;

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			grid2[i][j] = grid1[i][j];
			if (grid1[i][j] > MAX_GRAINS)
				stable = 0;
		}
	}

	return (stable);
}

/**
 * sum_grids - function that sums two grids or sandpiles
 * @grid1: first sandpile.
 * @grid2: second sandpile.
 * Return: no return.
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * toppling_round - function that iterates over sandpiles
 * @grid1: first sandpile.
 * @grid2: second sandpile.
 * Return: no return.
 */
void toppling_round(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < N_ROWS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			if (grid2[i][j] > MAX_GRAINS)
			{
				if (i > 0)
					grid1[i - 1][j] += 1;
				if (j < (N_COLS - 1))
					grid1[i][j + 1] += 1;
				if (i < (N_ROWS - 1))
					grid1[i + 1][j] += 1;
				if (j > 0)
					grid1[i][j - 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}
}


/**
 * sandpiles_sum - function that computes the sum of
 * two sandpiles.
 * @grid1: first sandpile.
 * @grid2: second sandpile.
 * Return: no return.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!check_is_stable(grid1, grid2))
	{
		print_sandpile(grid1);
		toppling_round(grid1, grid2);
	}
}
