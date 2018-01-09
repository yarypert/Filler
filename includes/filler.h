/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 04:07:17 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 07:14:24 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"

typedef struct	s_env
{
int			size_x;
int			size_y;
char		player;
char		enemy;
int			p_pos_x;
int			p_pos_y;
int			e_pos_x;
int			e_pos_y;

char		**piece;
char		**map;
int			end;

}				t_env;

#endif
