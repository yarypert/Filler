#include "../includes/filler.h"

void	initheatmap(t_env *env)
{
	int i = 0;
	int j = 0;
	while (i < env->size_y)
	{
		j = 0;
		while (j < env->size_x)
		{
			if (env->map[i][j] == env->enemy || env->map[i][j] == env->enemy + 32)
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
		while (i < env->size_y)
		{
			j = 0;
			while (j < env->size_x)
			{
				if (env->heat[i][j] > 0)
				{
					if (i + 1 < env->size_y && ((env->heat[i+1][j] > env->heat[i][j] + 1) || (env->heat[i+1][j] == 0)))
					{
						env->heat[i+1][j] = env->heat[i][j] + 1;
						check = 1;
					}
					if (j + 1 < env->size_x && ((env->heat[i][j+1] > env->heat[i][j] + 1) || (env->heat[i][j+1] == 0)))
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
	env->heat = (int **)ft_memalloc(sizeof(int *) * env->size_y);

	while (i < env->size_y)
	{
		env->heat[i] = (int *)ft_memalloc(sizeof(int) * env->size_x);
		i++;
	}
}
