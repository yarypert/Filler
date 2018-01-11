/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 04:07:17 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/11 06:16:58 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_env
{
int				size_x;
int				size_y;
int				psize_x;
int				psize_y;
int				ppos_x;
int				ppos_y;
int				epos_x;
int				epos_y;

char			enemy;
char			player;
char			**piece;
char			**map;
int				end;

}				t_env;

int				get_map(t_env *env);
int				get_pieces(t_env *env, char *line);
int				fwtpp(t_env *env);

#endif
