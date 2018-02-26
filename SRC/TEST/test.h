#ifndef TEST_H
# define TEST_H

#include "../../libft/libft.h"

typedef struct	s_env
{
	int o_min_y[2];
	int o_min_x[2];
}				t_env;


/*
 * **   main.c
 * */

void		backtoplayer(int **heat, int pcdx, int pcdy);
char		*read_file(char *file);
int			**placeenemy(char **map, int **heat, int x, int y);
char		*ft_strapp(char *str1, char *str2);

/*
 * ** display.c
 * */

void		printmap(char **map);
void		printintmap(int **intmap);
void		printposition(int x, int y);
void		printpiece(char **piece);

/*
 * ** heatmap.c
 * */

int			**intheatmap(int x, int y);
int			**createheat(char **map, int **heat, int x, int y);
int			**initheatmap(char **map, int **intmap);

/*
* ** offset.c
* */

void		offset(char **piece, t_env *env);

/*
 * ** place.c
 * */

void		findposition(int **heat, char **piece, char **map);
void		can_pose_it(char **map, char **piece, int pcdx, int pcdy);
void		can_pose_it_two(char **map, char **piece, int pcdx, int pcdy);
int			piece_size(char **piece, char axe);

#endif
