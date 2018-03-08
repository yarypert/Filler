/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:34:35 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:34:37 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_memjoin(void *p1, size_t l1, void *p2, size_t l2)
{
	char	*res;

	if (!p1 || !p2 || !(l1 + l2) || !(res = (char *)ft_memalloc(l1 + l2)))
		return (NULL);
	ft_memcpy(res, p1, l1);
	ft_memcpy(res + l1, p2, l2);
	return (res);
}
