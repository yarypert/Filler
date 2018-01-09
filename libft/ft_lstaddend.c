/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 00:21:57 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/09 00:22:01 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*plist;

	if (!new || !alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	plist = ft_lstend(*alst);
	plist->next = new;
}
