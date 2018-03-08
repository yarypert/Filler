/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 08:17:23 by yarypert          #+#    #+#             */
/*   Updated: 2018/03/08 17:31:57 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t x, size_t y)
{
	char **tab;
	int i;

	i = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * y);

	while (i < (int)y)
	{
		tab[i] = (char *)ft_memalloc(sizeof(char) * x);
		i++;
	}
	return (tab);
}
