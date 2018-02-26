/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:57:27 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/26 10:14:04 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char		*ft_strapp(char *str1, char *str2)
{
	char *tmp;

	if (str1 && str2)
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
			if (map[i][j] == 'o' || map[i][j] == 'O')
				heat[i][j] = 0;
			j++;
		}
		i++;
	}
	return(heat);
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
		offset(piece);
		intmap = createheat(map, initheatmap(map, intheatmap(25, 10)), 25, 10);
		printintmap(intmap);
		printpiece(piece);
	}
	else
		ft_putendl("Not Right Arguments Number");
}
