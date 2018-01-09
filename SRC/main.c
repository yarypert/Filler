/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 02:42:41 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 08:36:48 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int main(void)
{
	char	*line;
	t_env	*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (-1);
	get_next_line(0, &line);
	env->player = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	while (1337)
	{
		get_next_line(0, &line);
		env->size_y = ft_atoi(&line[8]);
		env->size_x = ft_atoi(&line[11]);
		get_map(env);
		fwtpp(env);
		put_pieces(env);
		if (env->end == 1)
			break;
	}
	free(env);
	return 0;
}
