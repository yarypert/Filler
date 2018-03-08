/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:18:51 by yarypert          #+#    #+#             */
/*   Updated: 2018/03/08 19:55:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		countpiece(t_env *env)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < env->psize_y)
	{
		j = 0;
		while (j < env->psize_x)
		{
			if (env->piece[i][j] == '*')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		dtw(int i, int j, t_env *env)
{
	if ((i < 0 || j < 0) || (i >= env->size_y || j >= env->size_x))
		;
	else if ((env->map[i][j] == env->player ||
				env->map[i][j] == env->player + 32)
			&& (env->piece[env->pi][env->pj] == '*' && env->c == 0))
	{
		env->co++;
		env->c++;
	}
	else if ((env->map[i][j] == env->player ||
				env->map[i][j] == env->player + 32)
			&& (env->piece[env->pi][env->pj] == '*' && env->c != 0))
		return (0);
	else if ((env->map[i][j] == env->enemy
				|| env->map[i][j] == env->enemy + 32)
			&& (env->piece[env->pi][env->pj] == '*'))
		return (0);
	else if (env->map[i][j] == '.' && env->piece[env->pi][env->pj] == '*')
	{
		env->heatpiece = env->heatpiece + env->heat[i][j];
		env->co++;
	}
	return (1);
}

int		compare(t_env *env)
{
	int i;
	int j;

	env->c = 0;
	env->co = 0;
	env->heatpiece = 0;
	env->pi = 0;
	i = env->mapi;
	while (env->pi < env->psize_y)
	{
		env->pj = 0;
		j = env->mapj;
		while (env->pj < env->psize_x)
		{
			if (dtw(i, j, env) == 0)
				return (0);
			env->pj++;
			j++;
		}
		env->pi++;
		i++;
	}
	if (env->c != 1 || env->co != env->count)
		return (0);
	return (1);
}

void	init_for_fp(t_env *env)
{
	env->countend = 0;
	env->finalx = 0;
	env->finaly = 0;
	env->count = countpiece(env);
	env->mapi = 0 - (env->psize_y - 1);
	env->heatsave = 2147483647;
}

void	findposition(t_env *env)
{
	init_for_fp(env);
	while (env->mapi <= env->size_y - (env->psize_y) + 1)
	{
		env->mapj = 0 - (env->psize_x - 1);
		while (env->mapj <= env->size_x - (env->psize_x) + 1)
		{
			if (compare(env) == 1)
			{
				if (env->heatpiece < env->heatsave)
				{
					env->heatsave = env->heatpiece;
					env->finalx = env->mapj;
					env->finaly = env->mapi;
				}
			}
			else if (compare(env) == 0)
				env->countend++;
			env->mapj++;
		}
		env->mapi++;
	}
	if (env->countend == (env->size_y + 1) * (env->size_x + 1))
		 env->end = 1;
}
