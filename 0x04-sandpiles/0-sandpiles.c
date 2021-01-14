#include "sandpiles.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *chek_grid - pour verif de grid
 *@grid1: matrice
 *Return: int(mean true)
 */
int chek_grid(int grid1[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (0);
			}

		}
	}
	return (1);
}
/**
 *sallah_grid - fonction de rectification de grid
 *@grid1: matrice
 *Return: void(mean true)
 */
void sallah_grid(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (j + 1 < 3)
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
				if (j - 1 > -1)
					grid1[i][j - 1] = grid1[i][j - 1] + 1
				grid1[i][j] = grid1[i][j] - 4;
				if (i + 1 < 3)
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				if (i - 1 > -1)
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
;
			}
		}

	}
}
/**
 *sandpiles_sum - main function
 *@grid1: matrice
 *@grid2: matrice
 *Return: nothing(mean true)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid1[i][j] = grid2[i][j] + grid1[i][j];
		}

	}


	while (!chek_grid(grid1))
	{
		printf("=\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
					printf(" ");
				printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
		sallah_grid(grid1);

	}
}
