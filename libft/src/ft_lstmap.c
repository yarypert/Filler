/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:45:33 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:45:36 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*link;
	t_list	*next_link;
	t_list	*first_link;

	if (!lst)
		return (NULL);
	link = (*f)(lst);
	first_link = link;
	lst = lst->next;
	while (lst)
	{
		next_link = (*f)(lst);
		lst = lst->next;
		link->next = next_link;
		link = next_link;
	}
	return (first_link);
}
