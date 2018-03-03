#ifndef TEST_H
# define TEST_H

#include "../../libft/libft.h"

typedef struct	s_env
{
	int finalx;
	int finaly;
	int mapi;
	int mapj;
	char **map;
	char **piece;
	int **heat;
	int mapx;
	int mapy;
	int piecex;
	int piecey;
	int	heatpiece;
	int		end;
}				t_env;




char		*read_file(char *file);
char		*ft_strapp(char *str1, char *str2);

void		printmap(t_env *env);
void		printintmap(t_env *env);
void		printpiece(t_env *env);


void		intheatmap(t_env *env);
void		createheat(t_env *env);
void		initheatmap(t_env *env);

int			canplace(t_env *env);
void		findposition(t_env *env);
#endif
