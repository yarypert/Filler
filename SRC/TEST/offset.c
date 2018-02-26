/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:14:48 by atgerard          #+#    #+#             */
/*   Updated: 2018/02/26 10:49:44 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	offset(char **piece)
{
	int		i;
	int		j;
	int		start;
	int		o_min_y[2];
	int		o_min_x[2];
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
				o_min_y[0] = j;
				o_min_y[1] = i;
				save_min_x = o_min_y[0];
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
	o_min_x[0] = j;
	o_min_x[1] = i;
}
