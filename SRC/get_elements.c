/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:17:21 by yarypert          #+#    #+#             */
/*   Updated: 2018/03/07 14:24:06 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_map(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	if (!env->map)
		if (!(env->map = ft_tabnew(env->size_y, env->size_x + 1)))
			return (-1);
	get_next_line(0, &line);
	free(line);
	while (i <= env->size_y)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
			env->map[i] = ft_strdup(line + 4);
		else
			get_pieces(env, line);
		i++;
	}
	free (line);
	return (0);
}

int		get_pieces(t_env *env, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 6;
	env->psize_y = ft_atoi(&line[j]);
	while (ft_isdigit(line[j]))
		j++;
	j++;
	env->psize_x = ft_atoi(&line[j]);
	if (!env->piece)
	{
		if (!(env->piece = ft_tabnew(env->psize_y + 1, env->psize_x)))
			return (-1);
	}
	while (i < env->psize_y)
	{
		get_next_line(0, &line);
		env->piece[i] = ft_strdup(line);
		i++;
	}
	free (line);
	return (0);
}
