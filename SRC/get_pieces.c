/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 08:34:48 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/11 02:07:18 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_pieces(t_env *env, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 6;
	env->psize_y = ft_atoi(&line[j]);
	while (ft_isdigit(line[j]))
		j++;
	j++;
	env->psize_x = ft_atoi(&line[j]);
	if (!env->piece)
		if (!(env->piece = ft_tabnew(env->psize_y, env->psize_x)))
			return (-1);
	while (i < env->psize_y)
	{
		get_next_line(0, &line);
		env->piece[i] = ft_strdup(line);
		i++;
	}
	return (0);
}
