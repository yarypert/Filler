#include "../includes/filler.h"


void	put_pieces(t_env *env)
{
	ft_putnbr(env->finaly);
			ft_putchar(' ');
		ft_putnbr(env->finalx);
			ft_putchar('\n');
}


int		compare(t_env *env)
{
	int i;
	int j;
	int pi;
	int pj;
	int contact = 0;
	env->heatpiece = 0;
	pi = 0;
	i = env->mapi;
	while (pi < env->psize_y)
	{
		pj = 0;
		j = env->mapj;
		while (pj < env->psize_x)
		{
			if ((env->map[i][j] == env->player || env->map[i][j] == env->player + 32) && env->piece[pi][pj] == '*' && contact == 0)
				contact++;
			else if ((env->map[i][j] == env->player || env->map[i][j] == env->player + 32) && env->piece[pi][pj] == '*' && contact != 0)
				return(0);
			else if ((env->map[i][j] == env->enemy || env->map[i][j] == env->enemy + 32) && env->piece[pi][pj] == '*')
				return(0);
			else if (env->map[i][j] == '.' && env->piece[pi][pj] == '*')
				env->heatpiece = env->heatpiece + env->heat[i][j];
			pj++;
			j++;
		}
		pi++;
		i++;
	}
	if (contact != 1)
		return(0);
	return(1);
}

void	findposition(t_env *env)
{
	int heatsave = 2147483647;
	env->mapi = 0;
	while (env->mapi < env->size_y - (env->psize_y - 1))
	{
		env->mapj = 0;
		while (env->mapj < env->size_x - (env->psize_x - 1))
		{
			if (compare(env) == 1)
			{
				if (env->heatpiece < heatsave)
				{
					heatsave = env->heatpiece;
					env->finalx = env->mapj;
					env->finaly = env->mapi;
				}
			else
				env->end = 1;
			}
			env->mapj++;
		}
		env->mapi++;
	}
}
