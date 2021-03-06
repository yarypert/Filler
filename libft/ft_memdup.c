/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:27:28 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:27:31 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memdup(void *p, size_t l)
{
	void	*r;

	return ((!p || !l || !(r = ft_memalloc(l))) ? NULL : ft_memcpy(r, p, l));
}
