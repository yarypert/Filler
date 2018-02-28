#ifndef TEST_H
# define TEST_H

#include "../../libft/libft.h"

typedef struct	s_env
{
	int		enemyx;
	int		enemyy;
	int		playerx;
	int		playery;
	int		end;
	int placex;
	int placey;
	int i;
	int j;
	int X;
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

void		offset_ul(char **piece, t_env *env);
void		offset_ur(char **piece, t_env *env);
void		offset_ll(char **piece, t_env *env);
void		offset_lr(char **piece, t_env *env);

/*
 * ** place.c
 * */

void		findposition(int **heat, char **piece, char **map, t_env *env);
void		findpositionenemy(int **heat, char **piece, char **map, t_env *env);
void		can_place_it(char **map, char **piece, t_env *env);
int			piece_size(char **piece, char axe);

/*
 * ** canplace.c
 * */

int			cpul(char **piece, char **map, t_env *env);
int			cpur(char **piece, char **map, t_env *env);
int			cpll(char **piece, char **map, t_env *env);
int			cplr(char **piece, char **map, t_env *env);
void		canplaceit(char **map, char **piece, t_env *env);

#endif
