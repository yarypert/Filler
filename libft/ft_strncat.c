/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:29:26 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:29:28 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[i + start] = s2[i];
		i++;
	}
	s1[i + start] = '\0';
	return (s1);
}
