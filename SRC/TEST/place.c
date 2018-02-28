#include "test.h"

void findposition(int **heat, char **piece, char **map, t_env *env)
{
	int i;
	int j;
	int check = 1;
	int pcd = 2147483647;
	int pcdx = 0;
	int pcdy = 0;

	(void)piece;
	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 25)
			{
				if(heat[i][j] == 0)
				{
					if (j - 1 >= 0 && (heat[i][j - 1] != 0 && heat[i][j - 1] < pcd))
					{
						pcd = heat[i][j - 1];
						pcdx = j - 1;
						pcdy = i;
						check = 1;
					}
					if (j+1 <= 24 && (heat[i][j + 1] != 0 && heat[i][j + 1] < pcd))
					{
						pcd = heat[i][j + 1];
						pcdx = j + 1;
						pcdy = i;
						check = 1;
					}
					if (i-1 >= 0 && (heat[i - 1][j] != 0 && heat[i-1][j] < pcd))
					{
						pcd = heat[i - 1][j];
						pcdx = j;
						pcdy = i - 1;
						check = 1;
					}
					if (i + 1 <= 10 && (heat[i + 1][j] != 0 && heat[i+1][j] < pcd))
					{
						pcd = heat[i + 1][j];
						pcdx = j;
						pcdy = i + 1;
						check = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	env->playerx = pcdx;
	env->playery = pcdy;
	printf("la piece doit contenir la case en X = %d et Y = %d\n", pcdx, pcdy);
}

void findpositionenemy(int **heat, char **piece, char **map, t_env *env)
{
	int i;
	int j;
	int check = 1;
	int pcd = 2147483647;
	int pcdx = 0;
	int pcdy = 0;

	(void)piece;
	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 25)
			{
				if(heat[i][j] == 0)
				{
					if (j - 1 >= 0 && (heat[i][j - 1] != 0 && heat[i][j - 1] < pcd))
					{
						pcd = heat[i][j - 1];
						pcdx = j - 1;
						pcdy = i;
						check = 1;
					}
					if (j+1 <= 24 && (heat[i][j + 1] != 0 && heat[i][j + 1] < pcd))
					{
						pcd = heat[i][j + 1];
						pcdx = j + 1;
						pcdy = i;
						check = 1;
					}
					if (i-1 >= 0 && (heat[i - 1][j] != 0 && heat[i-1][j] < pcd))
					{
						pcd = heat[i - 1][j];
						pcdx = j;
						pcdy = i - 1;
						check = 1;
					}
					if (i + 1 <= 10 && (heat[i + 1][j] != 0 && heat[i+1][j] < pcd))
					{
						pcd = heat[i + 1][j];
						pcdx = j;
						pcdy = i + 1;
						check = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	env->enemyx = pcdx;
	env->enemyy = pcdy;
}

int		piece_size(char **piece, char axe)
{
	int		i;
	int		j;

	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
			j++;
		i++;
	}
	if (axe == 'x')
		return (j);
	return (i);
}
