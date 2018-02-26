/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:15:16 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/26 13:01:19 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	put_pieces(t_env *env)
{
	ft_putnbr(env->ppos_y);
	ft_putchar(' ');
	ft_putnbr(env->ppos_x);
	ft_putchar('\n');
}
