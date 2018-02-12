/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 02:42:41 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/12 14:57:25 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int main(void)
{
	char	*line;
	t_env	*env;

	int i = 0;
	if (!(env = ft_memalloc(sizeof(t_env))))
		return (-1);
	get_next_line(0, &line);
	env->player = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	while (i < 100)
	{
		get_next_line(0, &line);
		env->size_y = ft_atoi(&line[8]);
		env->size_x = ft_atoi(&line[11]);
		get_map(env);
		//fwtpt(env);
		//put_pieces(env);
		if (env->end == 1)
			break;
	i++;
	}
	free(env);
	return 0;
}
