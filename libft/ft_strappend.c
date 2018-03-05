/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:28:18 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:28:22 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strappend(char **s1, char **s2, char c)
{
	char	*tmp;

	if (s1 && *s1 && s2 && *s2)
		tmp = ft_strjoin(*s1, *s2);
	else if (s1 && *s1)
		tmp = ft_strdup(*s1);
	else if (s2 && *s2)
		tmp = ft_strdup(*s2);
	else
		tmp = ft_strdup("");
	if (c == 'F' || c == 'B')
		ft_strdel(s1);
	if (c == 'S' || c == 'B')
		ft_strdel(s2);
	return (tmp);
}
