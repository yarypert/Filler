/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:31:20 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:31:22 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_addchar(char c, char **str, char where)
{
	char	*buf;

	buf = ft_strnew(1);
	buf[0] = c;
	if (where == 'B')
		buf = ft_strappend(&buf, str, 'B');
	else
		buf = ft_strappend(str, &buf, 'B');
	return (buf);
}

char		*ft_uimaxtoa(uintmax_t n, unsigned int base)
{
	char	*str;
	char	c;

	str = NULL;
	if (!n)
		str = ft_addchar('0', &str, 'B');
	else
	{
		while (n)
		{
			c = n % base;
			c = (c < 10) ? c + '0' : c - 10 + 'a';
			str = ft_addchar(c, &str, 'B');
			n /= base;
		}
	}
	return (str);
}
