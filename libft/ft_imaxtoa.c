/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:33:10 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:33:12 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t n, unsigned int base)
{
	char	*str;
	char	*tmp;

	tmp = "-";
	str = ft_uimaxtoa((uintmax_t)((n < 0) ? -n : n), base);
	return ((n < 0) ? ft_strappend(&tmp, &str, 'S') : str);
}
