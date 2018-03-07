/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:44:38 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:44:39 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*link;
	t_list	*next_link;

	if (!alst)
		return ;
	link = *alst;
	while (link)
	{
		next_link = link->next;
		ft_lstdelone(&link, del);
		free(link);
		link = next_link;
	}
	*alst = NULL;
}
