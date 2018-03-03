#include "test.h"

void	printpiece(t_env *env)
{
	int i = 0;
	int j = 0;
	while (i < env->piecey)
	{
		j = 0;
		while (j < env->piecex)
		{
			ft_putchar(env->piece[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	printintmap(t_env *env)
{
	int i = 0;
	int j = 0;
	while (i < env->mapy)
	{
		j = 0;
		while (j < env->mapx)
		{
			printf("%-3d", (env->heat[i][j]));
			j++;
		}
		printf("\n");
		i++;
	}
}

void	printmap(t_env *env)
{
	int i = 0;
	int j = 0;
	while (i < env->mapy)
	{
		j = 0;
		while (j < env->mapx)
		{
			ft_putchar(env->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
