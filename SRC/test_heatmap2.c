/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:57:27 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/19 22:24:01 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static char		*ft_strapp(char *str1, char *str2)
{
	char *tmp;

	if (str1 &&	 str2)
	{
		tmp = ft_strjoin(str1, str2);
		free(str1);
		return (tmp);
	}
	return (NULL);
}

char	*read_file(char *file)
{
	int		fd;
	int		ret;
	char	str[BUFF_SIZE];
	char	*grid;

	grid = ft_strnew(1);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("Can't open file");
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		grid = ft_strapp(grid, str);
	}
	if (ret == -1)
		ft_error("Can't read file");
	close(fd);
	return (grid);
}

void printintmap(int **intmap)
{
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			intmap[i][j]--;
			printf("%-3d", (intmap[i][j]));
			j++;
		}
		printf("\n");
		i++;
	}
}

void printmap(char **map)
{
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		**initheatmap(char **map, int **intmap)
{
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			if (map[i][j] == 'O' || map[i][j] == 'o')
				intmap[i][j] = 1;
			else
				intmap[i][j] = 0;
			j++;
		}
		i++;
	}
	return(intmap);
}


int **placeenemy(char **map, int **heat, int x, int y)
{
	int i;
	int j;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map[i][j] == 'x' || map[i][j] == 'X')
				heat[i][j] = 0;
			j++;
		}
		i++;
	}
	return(heat);
}

int **createheat(char **map, int **heat, int x, int y)
{
	int i;
	int j;
	int check = 1;

	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				if (heat[i][j] > 0)
				{
					if (i + 1 < y && ((heat[i+1][j] > heat[i][j] + 1) || (heat[i+1][j] == 0)))
					{
						heat[i+1][j] = heat[i][j] + 1;
						check = 1;
					}
					if (j + 1 < x && ((heat[i][j+1] > heat[i][j] + 1) || (heat[i][j+1] == 0)))
					{
						heat[i][j+1] = heat[i][j] + 1;
						check = 1;
					}
					if (i - 1 >= 0 && ((heat[i-1][j] > heat[i][j] + 1) || (heat[i-1][j] == 0)))
					{
						heat[i-1][j] = heat[i][j] + 1;
						check = 1;
					}
					if (j - 1 >= 0 && ((heat[i][j-1] > heat[i][j] + 1) || (heat[i][j-1] == 0)))
					{
						heat[i][j-1] = heat[i][j] + 1;
						check = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	heat = placeenemy(map, heat, x, y);
	return (heat);
}

int		**intheatmap(int x, int y)
{
	int		**heat;
	int		i;

	i = 0;
	heat = (int **)ft_memalloc(sizeof(int *) * y);

	while (i < y)
	{
		heat[i] = (int *)ft_memalloc(sizeof(int) * x);
		i++;
	}
	return (heat);
}

void	printpiece(char **piece)
{
	int i = 0;
	int j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(piece[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	printposition(int x, int y)
{
	ft_putstr("coordonees X = ");
	ft_putnbr(x);
	ft_putstr("\n\n");
	ft_putstr("coordonees Y = ");
	ft_putnbr(y);
	ft_putstr("\n");
}

void backtoplayer(int **heat, int pcdx, int pcdy)
{
	int i;
	int j;
	int end = 0;
	i = pcdy;
	j = pcdx;
	while (end == 0)
	{
		if(heat[i+1][j] == heat[i][j] - 1 && heat[i+1][j] != 0)
			i++;
		else if(heat[i-1][j]== heat[i][j] - 1 && heat[i+1][j] != 0)
			i--;
		else if(heat[i][j+1] == heat[i][j] - 1 && heat[i][j+1] != 0)
			j++;
		else if(heat[i][j-1] == heat[i][j] - 1 && heat[i][j-1] != 0)
			j--;
		else
			end = 1;
	}
	ft_putstr("la piece a poser doit etre en X (en partant de 0) = ");
	ft_putnbr(j);
	ft_putchar('\n');
	ft_putstr("la piece a poser doit etre en Y (en partant de 0) = ");
	ft_putnbr(i);
	ft_putchar('\n');
}

void findposition(int **heat, char **piece)
{
	int i;
	int j;
	int check = 1;
	int pcd = 2147483647;
	int pcdx = 0;
	int pcdy = 0;
	while (check > 0)
	{
		check = 0;
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 25)
			{
				if(heat[i][j] == -1)
				{
					if (j - 1 >= 0 && (heat[i][j - 1] != -1 && heat[i][j - 1] < pcd))
					{
						pcd = heat[i][j - 1];
						pcdx = j - 1;
						pcdy = i;
						check = 1;
					}
					if (j+1 <= 24 && (heat[i][j + 1] != -1 && heat[i][j + 1] < pcd))
					{
						pcd = heat[i][j + 1];
						pcdx = j + 1;
						pcdy = i;
						check = 1;
					}
					if (i-1 >= 0 && (heat[i - 1][j] != -1 && heat[i-1][j] < pcd))
					{
						pcd = heat[i - 1][j];
						pcdx = j;
						pcdy = i - 1;
						check = 1;
					}
					if (i + 1 <= 10 && (heat[i + 1][j] != -1 && heat[i+1][j] < pcd))
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
	backtoplayer(heat,pcdx, pcdy);
}

int		main(int argc, char **argv)
{
	char	**map;
	char	**heat;
	int		**intmap;
	char	**piece;
	if (argc == 3)
	{
		map = ft_strsplit(read_file(argv[1]), '\n');
		piece = ft_strsplit(read_file(argv[2]), '\n');
		intmap = createheat(map, initheatmap(map, intheatmap(25, 10)), 25, 10);
		printintmap(intmap);
		printpiece(piece);
		findposition(intmap, piece);
	}
	else
		ft_putendl("Not Right Arguments Number");
}
