/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:02:38 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/12 17:15:05 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_map(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	if (!env->map)
		if (!(env->map = ft_tabnew(env->size_y, env->size_x)))
			return (-1);
	get_next_line(0, &line);
	while(i <= env->size_y)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
			env->map[i] = ft_strdup(line + 4);
		else
			get_pieces(env, line);
		i++;
	}
	return(0);
}
