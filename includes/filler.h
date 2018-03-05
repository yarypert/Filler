/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 04:07:17 by yarypert          #+#    #+#             */
/*   Updated: 2018/03/05 13:15:38 by yarypert         ###   ########.fr       */
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
char			enemy;
char			player;
char			**piece;
char			**map;
int				end;
int				**heat;
int				heatpiece;
int				mapi;
int				mapj;
int				finalx;
int				finaly;
}				t_env;

/*
 * ** get_elements.c
 * */

int				get_map(t_env *env);
int				get_pieces(t_env *env, char *line);

/*
 * ** canplace.c
 * */

void			put_pieces(t_env *env);
int				compare(t_env *env);
void			findposition(t_env *env);

/*
 * ** heatmap.c
 * */

void			initheatmap(t_env *env);
void			createheat(t_env *env);
void			intheatmap(t_env *env);

#endif
