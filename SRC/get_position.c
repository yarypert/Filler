/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:34:57 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/11 02:44:56 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_position(t_env *env)
{
	int i;
	int j;

	i = 0;
	if (env->player == 'O')
		env->enemy = 'X';
	else if (env->player == 'X') 
		env->enemy = 'O';
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
}
