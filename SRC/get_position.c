/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:34:57 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/12 16:09:37 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_position(t_env *env)
{
	int i;
	int j;

	i = 0;
	env->enemy = (env->player == 'O') ? 'X' : 'O';
	while(i < env->size_y)
	{
		j = 0;
		while (j < env->size_x)
		{
			if (env->map[i][j] == env->enemy)
			{
			env->epos_x = j;
			env->epos_y = i;
			}
			if (env->map[i][j] == env->player)
			{
			env->ppos_x = j;
			env->ppos_y = i;
			}
			j++;
		}
		i++;
	}
	env->algo = check_udlr(env);
}

int		check_udlr(t_env *env)
{
	if (env->epos_x <= env->ppos_x && env->epos_y < env->ppos_y)
		return(1);
	if (env->epos_x > env->ppos_x && env->epos_y <= env->ppos_y)
		return(2);
	if (env->epos_x < env->ppos_x && env->epos_y >= env->ppos_y)
		return(3);
	if (env->epos_x >= env->ppos_x && env->epos_y > env->ppos_y)
		return(4);
	return(0);
}
