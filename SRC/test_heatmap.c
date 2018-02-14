/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:57:27 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/14 17:03:26 by yarypert         ###   ########.fr       */
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



int		**heatmap(int x, int y)
{
	int **heat;
	int i;

	i = 0;
	heat = (int **)ft_memalloc(sizeof(int *) * y);

	while (i < y)
	{
		heat[i] = (int *)ft_memalloc(sizeof(int) * x);
		i++;
	}
	return (heat);
}

int **fillmap(int **heat, int x, int y, int posx, int posy)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == posy && j == posx)
				heat[i][j] = 1;
			else
				heat[i][j] = 0;
			j++;
		}
		i++;
	}
	return (heat);
}

void	printtab(int **heat, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%-4d", heat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int **createheat(int **heat, int x, int y)
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
	return (heat);
}

/*
int		main(int argc, char **argv)
{
	int **heat;
	int x;
	int y;
	int posx;
	int posy;

	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	posx = ft_atoi(argv[3]);
	posy = ft_atoi(argv[4]);
	if (posx > x || posy > y)
		ft_error("NIKTAMERE");
	heat = heatmap(x, y);
	heat = fillmap(heat, x, y, posx, posy);
	heat = createheat(heat, x, y);
	printtab(heat,x,y);
	ft_putendl("////////////////////////////");
	return 0;
}*/

int		countbn(char *read)
{
	int i;
	int bn;
	i = 0;
	bn = 0;

	while (i < ft_strlen(read))
	{
		if(read[i] == '\n')
			bn++;
		i++;
	}
	return (bn);
}

int main(int argc, char **argv)
{
	char **map;
	if (argc == 2)
	{
		map = ft_strsplit(read_file(argv[1]), '\n');
	}
	else
		return 0;
}
