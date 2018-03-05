/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:21:37 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:21:40 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			addchar(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != 1)
		i++;
	str[i] = str[i] ? c : '\0';
}

static void			itoa_rec(unsigned int n, char *str)
{
	if (n < 10)
		addchar(n + '0', str);
	else
	{
		itoa_rec(n / 10, str);
		itoa_rec(n % 10, str);
	}
}

static char			*initstr(int n)
{
	unsigned int	tmp;
	size_t			size;
	char			*str;

	tmp = (n < 0) ? -n : n;
	size = (size_t)(ft_magnitude(tmp) + (n < 0)) * sizeof(char);
	str = ft_strnew(size);
	if (str)
	{
		ft_memset(str, 1, size);
		str[size] = '\0';
	}
	return (str);
}

char				*ft_itoa(int n)
{
	char	*res;

	res = initstr(n);
	if (res && n < 0)
	{
		addchar('-', res);
		if (n < -9)
			itoa_rec(n / -10, res);
		addchar(-(n % 10) + '0', res);
	}
	else if (res)
		itoa_rec(n, res);
	return (res);
}
