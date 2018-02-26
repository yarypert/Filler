#include "test.h"

void	printpiece(char **piece)
{
	int i = 0;
	int j = 0;
	while (i < 3)
	{
		j	 = 0;
		while (j < 4)
		{
			ft_putchar(piece[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	printposition(int x, int y)
{
	ft_putstr("coordonees X = ");
	ft_putnbr(x);
	ft_putstr("\n\n");
	ft_putstr("coordonees Y = ");
	ft_putnbr(y);
	ft_putstr("\n");
}

void printintmap(int **intmap)
{
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			intmap[i][j]--;
			printf("%-3d", (intmap[i][j]));
			j++;
		}
		printf("\n");
		i++;
	}
}

void printmap(char **map)
{
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
