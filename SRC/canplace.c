/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:18:51 by yarypert          #+#    #+#             */
/*   Updated: 2018/03/07 14:22:14 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		countpiece(t_env *env)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < env->psize_y)
	{
		j = 0;
		while(j < env->psize_x)
		{
			if (env->piece[i][j] == '*')
				count++;
			j++;
		}
		i++;
	}
	return(count);
}

void	put_pieces(t_env *env)
{
	ft_putnbr(env->finaly);
	ft_putchar(' ');
	ft_putnbr(env->finalx);
	ft_putchar('\n');
	free(env->map);
	free(env->piece);
	env->map = NULL;
	env->piece = NULL;
}

int		compare(t_env *env)
{
	int i;
	int j;
	int pi;
	int pj;
	int contact = 0;
	int count = 0;
	env->heatpiece = 0;
	pi = 0;
	i = env->mapi;
	while (pi < env->psize_y)
	{
		pj = 0;
		j = env->mapj;
		while (pj < env->psize_x)
		{
			if ((i < 0 || j < 0) || (i >= env->size_y || j >= env->size_x))
				;
			else if ((env->map[i][j] == env->player || env->map[i][j] == env->player + 32) && env->piece[pi][pj] == '*' && contact == 0)
			{
				count++;
				contact++;
			}
			else if ((env->map[i][j] == env->player || env->map[i][j] == env->player + 32) && env->piece[pi][pj] == '*' && contact != 0)
				return(0);
			else if ((env->map[i][j] == env->enemy || env->map[i][j] == env->enemy + 32) && env->piece[pi][pj] == '*')
				return(0);
			else if (env->map[i][j] == '.' && env->piece[pi][pj] == '*')
			{
				env->heatpiece = env->heatpiece + env->heat[i][j];
				count++;
			}
			pj++;
			j++;
		}
		pi++;
		i++;
	}
	if (contact != 1 || count != env->count)
		return(0);
	return(1);
}

void	findposition(t_env *env)
{
	env->countend = 0;
	env->finalx = 0;
	env->finaly = 0;
	int heatsave = 2147483647;
	env->count = countpiece(env);
	env->mapi = 0 - (env->psize_y - 1);
	while (env->mapi <= env->size_y - (env->psize_y) + 1)
	{
		env->mapj = 0 - (env->psize_x - 1);
		while (env->mapj <= env->size_x - (env->psize_x) + 1)
		{
			if (compare(env) == 1)
			{
				if (env->heatpiece < heatsave)
				{
					heatsave = env->heatpiece;
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
	if(env->countend == (env->size_y + 1) * (env->size_x + 1))
		env->end = 1;
}
