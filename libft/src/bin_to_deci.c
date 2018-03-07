/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_deci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:39:56 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:39:58 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		bin_to_deci(char *nbr)
{
	int		i;
	int		res;

	if (nbr[0] == '0' && !nbr[1])
		return (0);
	i = 8;
	res = 0;
	while (i-- > 0)
		res += (nbr[i] - '0') * ft_recur_power(2, 7 - i);
	return (res);
}
