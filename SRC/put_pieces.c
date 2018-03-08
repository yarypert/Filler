/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:04:52 by atgerard          #+#    #+#             */
/*   Updated: 2018/03/08 20:07:55 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	put_pieces(t_env *env)
{
	ft_putnbr(env->finaly);
	ft_putchar(' ');
	ft_putnbr(env->finalx);
	ft_putchar('\n');
	//	free(env->map);
	//	free(env->piece);
	//	env->map = NULL;
	//	env->piece = NULL;
}

void	del_map(t_env *env)
{
	int	i;

	i = -1;
	while (env->map && env->map[++i])
		ft_memdel((void**)&(env->map[i]));
	ft_memdel((void**)&(env->map));
}

void	del_heat(t_env *env)
{
	int	i;

	i = -1;
	while (env->heat && env->heat[++i])
		ft_memdel((void**)&(env->heat[i]));
	ft_memdel((void**)&(env->heat));
}

void	del_piece(t_env *env)
{
	int	i;

	i = -1;
	while (env->piece && env->piece[++i])
		ft_memdel((void**)&(env->piece[i]));
	ft_memdel((void**)&(env->piece));
}

void	del_struct(t_env *env)
{
	del_map(env);
	del_heat(env);
	del_piece(env);
}
