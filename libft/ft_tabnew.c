/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 08:17:23 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 08:24:30 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t x, size_t y)
{
	char **tab;
	char *line;
	size_t i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * y);
	line = (char *)malloc(sizeof(char) * x * y);
	while (i < y)
	{
		tab[i] = &line[i * x];
		i++;
	}
	return(tab);
}
