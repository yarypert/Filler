/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 04:12:31 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/07 04:12:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	char	*res;
	int		size;

	size = ft_strlen(s1);
	res = malloc(sizeof(char) * (size + 1));
	if (res)
	{
		ft_memcpy(res, s1, size);
		res[size] = '\0';
	}
	return (res);
}
