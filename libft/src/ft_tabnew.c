/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:56:16 by atgerard          #+#    #+#             */
/*   Updated: 2018/03/05 15:56:18 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
