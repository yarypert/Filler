/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:02:38 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 08:36:22 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_map(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	if (!env->map)
		if (!(env->map = ft_tabnew(env->size_y, env->size_x)))
			return (-1);
	while(i <= env->size_y)
	{
		get_next_line(0, &line);
		i++;
	}
	return(0);
}
