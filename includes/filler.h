/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 04:07:17 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/26 14:16:23 by yarypert         ###   ########.fr       */
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

int				**heat;
}				t_env;

/*
 * ** get_map.c
 * */

int				get_map(t_env *env);

/*
 * ** get_pieces.c
 * */

int				get_pieces(t_env *env, char *line);

/*
 * ** read.c
 * */

char			*ft_strapp(char *str1, char *str2);
char			*read_file(char *file);

/*
 * ** heatmap.c
 * */

void			initheatmap(t_env *env);
void			createheat(t_env *env);
void			intheatmap(t_env *env);
void			placeenemy(t_env *env);

#endif
