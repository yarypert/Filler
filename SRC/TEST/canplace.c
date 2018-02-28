#include "test.h"

int		cpur(char **piece, char **map, t_env *env)
{
	int can = 0;
	return(can);
}

int		cpll(char **piece, char **map, t_env *env)
{
	int can = 0;
	return(can);
}

int		cplr(char **piece, char **map, t_env *env)
{
	int can = 0;
	return(can);
}
int		cpul(char **piece, char **map, t_env *env)
{
	int can = 0;
	int	p_size_y = 2;
	int	p_size_x = 3;
	int	i = 0;
	int	j = 0;
	int indx = 0;
	int indy = 0;
	int okay = p_size_x * p_size_y;

	j = env->playerx;
	while (j < 10 && j >= 0 && indy < p_size_y)
	{
		i = env->playery;
		indx = 0;
		while (i < 25 && i >= 0 && indx < p_size_x)
		{
			if (map[i][j] == '.' && piece[indy][indx] == '*')
				okay--;
			else if (map[i][j] == '.' && piece[indy][indx] == '.')
				okay--;
			else if (map[i][j] != '.' && piece[indy][indx] == '*')
				;
			else if (map[i][j] != '.' && piece[indy][indx] == '.')
				okay--;
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

void	canplaceit(char **map, char **piece, t_env *env)
{
	env->placex = env->playerx - (3 - env->i);
	env->placey = env->playery - (2 - env->j);
	if(env->enemyx < env->playerx && env->enemyy <= env->playery)
	{
		if (cpul(piece, map, env) == 1)
		{
			printf("la piece peut etre posee en X = %d et Y = %d\n",env->placex, env->placey);
			env->i = 0;
			env->j = 0;
		}
		else

	}
	else if(env->enemyx >= env->playerx && env->enemyy < env->playery)
	{
		if (cpur(piece, map, env) == 1)
			;
	}
	else if(env->enemyx <= env->playerx && env->enemyy > env->playery)
	{
		if (cpll(piece, map, env) == 1)
			;
	}
	else if(env->enemyx > env->playerx && env->enemyy >= env->playery)
	{
		if (cplr(piece, map, env) == 1)
			;
	}
}
