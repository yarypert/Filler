/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_x_low_wp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:04:19 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/02 15:08:22 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putlong_x_low_wp(unsigned long nb)
{
	int		res;

	res = 1;
	if (nb / 16 > 0)
		res += ft_putlong_x_low_wp(nb / 16);
	return (res);
}
