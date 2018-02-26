/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:14:48 by atgerard          #+#    #+#             */
/*   Updated: 2018/02/26 18:44:38 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	offset(char **piece, t_env *env)
{
	int		i;
	int		j;
	int		start;
	int		save_min_x;

	save_min_x = 0;
	start = 0;
	i = 0;
	j = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '*' && start == 0)
			{
				start = 1;
				env->o_min_y[0] = j;
				env->o_min_y[1] = i;
				save_min_x = env->o_min_y[0];
			}
			if (piece[i][j] == '*' && j < save_min_x)
				save_min_x = j;
			j++;
		}
		i++;
	}
	i = 0;
	j = save_min_x;
	while (piece[i][j] != '*')
		i++;
	env->o_min_x[0] = j;
	env->o_min_x[1] = i;
	printf("min xx = %d\n min xy = %d\n min yx = %d\n min yy  %d\n", env->o_min_x[0], env->o_min_x[1], env->o_min_y[0], env->o_min_y[1]);
}
