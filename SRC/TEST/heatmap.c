#include "test.h"

int		**initheatmap(char **map, int **intmap)
{
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			if (map[i][j] == 'X' || map[i][j] == 'x')
				intmap[i][j] = 1;
			else
				intmap[i][j] = 0;
			j++;
		}
		i++;
	}
	return(intmap);
}

int **createheat(char **map, int **heat, int x, int y)
{
	int i;
	int j;
	int check = 1;

	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				if (heat[i][j] > 0)
				{
					if (i + 1 < y && ((heat[i+1][j] > heat[i][j] + 1) || (heat[i+1][j] == 0)))
					{
						heat[i+1][j] = heat[i][j] + 1;
						check = 1;
					}
					if (j + 1 < x && ((heat[i][j+1] > heat[i][j] + 1) || (heat[i][j+1] == 0)))
					{
						heat[i][j+1] = heat[i][j] + 1;
						check = 1;
					}
					if (i - 1 >= 0 && ((heat[i-1][j] > heat[i][j] + 1) || (heat[i-1][j] == 0)))
					{
						heat[i-1][j] = heat[i][j] + 1;
						check = 1;
					}
					if (j - 1 >= 0 && ((heat[i][j-1] > heat[i][j] + 1) || (heat[i][j-1] == 0)))
					{
						heat[i][j-1] = heat[i][j] + 1;
						check = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	heat = placeenemy(map, heat, x, y);
	return (heat);
}

int		**intheatmap(int x, int y)
{
	int	**heat;
	int	i;

	i = 0;
	heat = (int **)ft_memalloc(sizeof(int *) * y);

	while (i < y)
	{
		heat[i] = (int *)ft_memalloc(sizeof(int) * x);
		i++;
	}
	return (heat);
}
