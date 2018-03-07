/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:04:52 by atgerard          #+#    #+#             */
/*   Updated: 2018/03/07 16:05:50 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	put_pieces(t_env *env)
{
	ft_putnbr(env->finaly);
	ft_putchar(' ');
	ft_putnbr(env->finalx);
	ft_putchar('\n');
	free(env->map);
	free(env->piece);
	env->map = NULL;
	env->piece = NULL;
}
