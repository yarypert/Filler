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

void	size(t_env *env)
{
	int i = 0;
	while (env->piece[i])
	{
		env->piecex = ft_strlen(env->piece[0]);
		i++;
	}
	env->piecey = i;
	i = 0;
	while (env->map[i])
	{
		env->mapx = ft_strlen(env->map[0]);
		i++;
	}
	env->mapy = i;
}


int		main(int argc, char **argv)
{
	t_env	env;

	if (argc == 3)
	{
		env.map = ft_strsplit(read_file(argv[1]), '\n');
		env.piece = ft_strsplit(read_file(argv[2]), '\n');
		size(&env);
		intheatmap(&env);
		initheatmap(&env);
		createheat(&env);
		printmap(&env);
		printintmap(&env);
		printpiece(&env);
		findposition(&env);
		printf("poser la piece en X %d\n et poser la piece en Y%d\n", env.finalx, env.finaly);
	}
	else
		ft_putendl("Not Right Arguments Number");
}
