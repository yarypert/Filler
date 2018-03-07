/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 02:42:41 by yarypert          #+#    #+#             */
/*   Updated: 2018/03/07 21:31:37 by athanael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_env	*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (-1);
	get_next_line(0, &env->line);
	env->player = (ft_atoi(env->line + 10) == 1) ? 'O' : 'X';
	env->enemy = env->player == 'O' ? 'X' : 'O';
	//free(env->line);
	while (1)
	{
		get_next_line(0, &env->line);
		env->size_y = ft_atoi(&env->line[8]);
		env->size_x = ft_atoi(&env->line[11]);
		//free(env->line);
		get_map(env);
		intheatmap(env);
		initheatmap(env);
		createheat(env);
		findposition(env);
		put_pieces(env);
		if (env->end == 1)
			break ;
	}
	free(env);
	return (0);
}
