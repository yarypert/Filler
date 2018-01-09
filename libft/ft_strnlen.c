/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:30:30 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:30:32 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t				ft_strnlen(char *str, size_t size)
{
	size_t	res;

	res = 0;
	while (res < size && str[res])
		res++;
	return (res);
}
