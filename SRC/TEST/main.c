/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 02:57:27 by yarypert          #+#    #+#             */
/*   Updated: 2018/02/28 18:50:12 by yarypert         ###   ########.fr       */
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

char	**invert(char **heat)
{
	int i;
	int j;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			if (heat[i][j] == 'X')
				heat[i][j] = 'O';
			else if (heat[i][j] == 'O')
				heat[i][j] = 'X';
			j++;
		}
		i++;
	}
	return(heat);
}

void	init(t_env *env)
{
	env->i = 0;
	env->j = 0;
	env->placex = 0;
	env->placey = 0;
	env->X = 0;

}

int		main(int argc, char **argv)
{
	char	**map;
	char	**heat;
	int		**intmap;
	char	**piece;
	int		**intmapenemy;
	char	**mapenemy;
	t_env	env;

	(void)heat;
	if (argc == 3)
	{
		init(&env);
		map = ft_strsplit(read_file(argv[1]), '\n');
		piece = ft_strsplit(read_file(argv[2]), '\n');
		intmap = createheat(map, initheatmap(map, intheatmap(25, 10)), 25, 10);
		mapenemy = invert(map);
		intmapenemy = createheat(map, initheatmap(mapenemy, intheatmap(25, 10)), 25, 10);
		findposition(intmap, piece, map, &env);
		findpositionenemy(intmapenemy, piece, mapenemy, &env);
		canplaceit(map,piece,&env);
		printmap(map);
		printintmap(intmap);
		printf("\n\n");
		printintmap(intmapenemy);
		printpiece(piece);
		printf("\n");
	}
	else
		ft_putendl("Not Right Arguments Number");
}