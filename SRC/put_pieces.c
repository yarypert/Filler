/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:15:16 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/12 16:15:22 by yarypert         ###   ########.fr       */
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

//on a la direction de l'ennemi
//checker last position player
//recuperer la piece complete avec points
//verifier si elle passe dans la map
//gerer offset
//tester la pieces >
//retirer la piece <
//placer la pieces en contact avec les precedentes
