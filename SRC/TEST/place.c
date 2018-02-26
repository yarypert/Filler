#include "test.h"

void findposition(int **heat, char **piece, char **map)
{
	int i;
	int j;
	int check = 1;
	int pcd = 2147483647;
	int pcdx = 0;
	int pcdy = 0;

	(void)piece;
	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 25)
			{
				if(heat[i][j] == 0)
				{
					if (j - 1 >= 0 && (heat[i][j - 1] != 0 && heat[i][j - 1] < pcd))
					{
						pcd = heat[i][j - 1];
						pcdx = j - 1;
						pcdy = i;
						check = 1;
					}
					if (j+1 <= 24 && (heat[i][j + 1] != 0 && heat[i][j + 1] < pcd))
					{
						pcd = heat[i][j + 1];
						pcdx = j + 1;
						pcdy = i;
						check = 1;
					}
					if (i-1 >= 0 && (heat[i - 1][j] != 0 && heat[i-1][j] < pcd))
					{
						pcd = heat[i - 1][j];
						pcdx = j;
						pcdy = i - 1;
						check = 1;
					}
					if (i + 1 <= 10 && (heat[i + 1][j] != 0 && heat[i+1][j] < pcd))
					{
						pcd = heat[i + 1][j];
						pcdx = j;
						pcdy = i + 1;
						check = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	printf("la piece doit contenir la case en X = %d et Y = %d\n", pcdx, pcdy);
	can_pose_it(map, piece, pcdx, pcdy);
}

int		piece_size(char **piece, char axe)
{
	int		i;
	int		j;

	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
			j++;
		i++;
	}
	if (axe == 'x')
		return (j);
	return (i);
}
void	can_pose_it_two(char **map, char **piece, int pcdx, int pcdy)
{
	int		p_size_y;
	int		imap;
	int		jmap;
	int		test;
	int		save;

	test = 0;
	jmap = pcdy;
	imap = pcdx;
	p_size_y = piece_size(piece, 'y');
	save = p_size_y;
	if ((map[jmap][imap] == '.') && (imap >= 0 && jmap >= 0))
	{
		jmap--;
		test++;
		p_size_y--;
		while (p_size_y > 0)
		{
			if ((map[jmap][imap] == '.') && (imap >= 0 && jmap >= 0))
			{
				jmap--;
				p_size_y--;
				test++;
			}
			else
			{
				ft_putendl("La piece ne passe pas");
				exit(1);
			}
		}
	}
	if (test == save)
		ft_putendl("La piece rentre");
	else
		ft_putendl("La piece ne passe pas");
}

void	can_pose_it(char **map, char **piece, int pcdx, int pcdy)
{
	int		p_size_x;
	int		imap;
	int		jmap;
	int		test;
	int		save;

	test = 0;
	jmap = pcdy;
	imap = pcdx;
	p_size_x = piece_size(piece, 'x');
	save = p_size_x;
	if ((map[jmap][imap] == '.') && (imap >= 0 && jmap >= 0))
	{
		imap--;
		test++;
		p_size_x--;
		while (p_size_x > 0)
		{
			if ((map[jmap][imap] == '.') && (imap >= 0 && jmap >= 0))
			{
				imap--;
				p_size_x--;
				test++;
			}
			else
			{
				ft_putendl("La piece ne passe pas");
				exit(1);
			}
		}
	}
	if (test == save)
		can_pose_it_two(map, piece, pcdx, pcdy);
	else
		ft_putendl("La piece ne passe pas");
}
