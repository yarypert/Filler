#include "test.h"

int		cpul(char **map, char **piece, t_env *env)
{
	int can = 0;
	int	p_size_y = 3;
	int	p_size_x = 4;
	int	i = 0;
	int	j = 0;
	int indx = 3;
	int indy = 4;
	int okay = p_size_x * p_size_y;
	
	j = env->playery;
	while (j < 10 && j >= 0 && indy > 0)
	{
		i = env->playerx;
		indx = 3;
		while (i < 25 && i >= 0 && indx > 0)
		{
			if (map[i][j] == '.' && piece[indy][indx] == '*')
				okay--;
			else if (map[i][j] == '.' && piece[indy][indx] == '.')
				okay--;
			else if (map[i][j] != '.' && piece[indy][indx] == '*')
				;
			else if (map[i][j] != '.' && piece[indy][indx] == '.')
				okay--;
			indx--;
			i--;
		}
		indy--;
		j--;
	}
	if (okay == 0)
		can = 1;
	else
		can = 0;
	return(can);
}

int		cpur(char **piece, char **map, t_env *env)
{
	int can = 0;
	int	p_size_y = 3;
	int	p_size_x = 4;
	int	i = 0;
	int	j = 0;
	int indx = 0;
	int indy = 4;
	int okay = p_size_x * p_size_y;
	
	j = env->playery;
	while (j < 10 && j >= 0 && indy > 0)
	{
		i = env->playerx;
		indx = 3;
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
		indy--;
		j--;
	}
	if (okay == 0)
		can = 1;
	else
		can = 0;
	return(can);
}

int		cpll(char **piece, char **map, t_env *env)
{
	int can = 0;
	int	p_size_y = 3;
	int	p_size_x = 4;
	int	i = 0;
	int	j = 0;
	int indx = 3;
	int indy = 0;
	int okay = p_size_x * p_size_y;
	
	j = env->playery;
	while (j < 10 && j >= 0 && indy < p_size_y)
	{
		i = env->playerx;
		indx = 3;
		while (i < 25 && i >= 0 && indx > 0)
		{
			if (map[i][j] == '.' && piece[indy][indx] == '*')
				okay--;
			else if (map[i][j] == '.' && piece[indy][indx] == '.')
				okay--;
			else if (map[i][j] != '.' && piece[indy][indx] == '*')
				;
			else if (map[i][j] != '.' && piece[indy][indx] == '.')
				okay--;
			indx--;
			i--;
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

int		cplr(char **piece, char **map, t_env *env)
{
	int can = 0;
	int	p_size_y = 3;
	int	p_size_x = 4;
	int	i = 0;
	int	j = 0;
	int indx = 0;
	int indy = 0;
	int okay = p_size_x * p_size_y;
	
	j = env->playery;
	while (j < 10 && j >= 0 && indy < p_size_y)
	{
		i = env->playerx;
		indx = 3;
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
	if(env->enemyx < env->playerx && env->enemyy <= env->playery)
	{
		if (cpul(map, piece, env) == 1);
		else
			env->end = 1;
	}
	else if(env->enemyx >= env->playerx && env->enemyy > env->playery)
	{
		if (cpur(map, piece, env) == 1);
		else
			env->end = 1;
	}
	else if(env->enemyx <= env->playerx && env->enemyy < env->playery)
	{
		if (cpll(map, piece, env) == 1);
		else
			env->end = 1;
	}
	else if(env->enemyx > env->playerx && env->enemyy >= env->playery)
	{
		if (cplr(map, piece, env) == 1);
		else
			env->end = 1;
	}
}
