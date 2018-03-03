#include "test.h"

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
	while (pi < env->piecey)
	{
		pj = 0;
		j = env->mapj;
		while (pj < env->piecex)
		{
			if ((env->map[i][j] == 'X' || env->map[i][j] == 'x') && env->piece[pi][pj] == '*' && contact == 0)
				contact++;
			else if ((env->map[i][j] == 'X' || env->map[i][j] == 'x') && env->piece[pi][pj] == '*' && contact != 0)
				return(0);
			else if ((env->map[i][j] == 'O' || env->map[i][j] == 'o') && env->piece[pi][pj] == '*')
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
	while (env->mapi < env->mapy - (env->piecey - 1))
	{
		env->mapj = 0;
		while (env->mapj < env->mapx - (env->piecex - 1))
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

int		canplace(t_env *env)
{
	int can = 0;
	int	i = 0;
	int	j = 0;
	int indx = 0;
	int indy = 0;
	int okay = env->piecex * env->piecey;

	while (j < env->mapy && j >= 0 && indy < env->piecey)
	{
		indx = 0;
		while (i < env->mapx && i >= 0 && indx < env->piecex)
		{
			indx++;
			i++;
		}
		indy++;
		j++;
	}
	if (okay == 0)
		can = 1;
	else
		can = 0;
	return(can);
}
