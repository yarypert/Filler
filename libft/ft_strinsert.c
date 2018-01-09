/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:28:42 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:28:44 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strinsert(char **add, char **str, size_t where, char c)
{
	char	*res;

	if (!(add && *add && str && *str &&
		(res = ft_strnew(ft_strlen(*add) + ft_strlen(*str)))))
		return (NULL);
	ft_strcat(ft_strcat(ft_strncat(res, *str, where), *add), *str + where);
	if (c == 'F' || c == 'B')
		ft_strdel(add);
	if (c == 'S' || c == 'B')
		ft_strdel(str);
	return (res);
}
