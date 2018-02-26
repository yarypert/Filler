#ifndef TEST_H
# define TEST_H

#include "../../libft/libft.h"

/*
 * **   main.c
 * * */

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

#endif
