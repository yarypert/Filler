#include "test.h"

void	initheatmap(t_env *env)
{
	int i = 0;
	int j = 0;
	while (i < env->mapy)
	{
		j = 0;
		while (j < env->mapx)
		{
			if (env->map[i][j] == 'O' || env->map[i][j] == 'o')
				env->heat[i][j] = 1;
			else
				env->heat[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	createheat(t_env *env)
{
	int i;
	int j;
	int check = 1;

	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < env->mapy)
		{
			j = 0;
			while (j < env->mapx)
			{
				if (env->heat[i][j] > 0)
				{
					if (i + 1 < env->mapy && ((env->heat[i+1][j] > env->heat[i][j] + 1) || (env->heat[i+1][j] == 0)))
					{
						env->heat[i+1][j] = env->heat[i][j] + 1;
						check = 1;
					}
					if (j + 1 < env->mapx && ((env->heat[i][j+1] > env->heat[i][j] + 1) || (env->heat[i][j+1] == 0)))
					{
						env->heat[i][j+1] = env->heat[i][j] + 1;
						check = 1;
					}
					if (i - 1 >= 0 && ((env->heat[i-1][j] > env->heat[i][j] + 1) || (env->heat[i-1][j] == 0)))
					{
						env->heat[i-1][j] = env->heat[i][j] + 1;
						check = 1;
					}
					if (j - 1 >= 0 && ((env->heat[i][j-1] > env->heat[i][j] + 1) || (env->heat[i][j-1] == 0)))
					{
						env->heat[i][j-1] = env->heat[i][j] + 1;
						check = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
}

void	intheatmap(t_env *env)
{
	int	i;

	i = 0;
	env->heat = (int **)ft_memalloc(sizeof(int *) * env->mapy);

	while (i < env->mapy)
	{
		env->heat[i] = (int *)ft_memalloc(sizeof(int) * env->mapx);
		i++;
	}
}
