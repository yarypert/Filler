/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 04:13:00 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/07 04:13:42 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcount(const char *s1, const char *s2)
{
	int		count;
	char	*check;

	count = 0;
	check = (char *)s1;
	if (*s1 == '\0' || !s1 || *s2 == '\0' || !s2)
		return (count);
	while (check)
	{
		check = ft_strnstr(check, s2, ft_strlen(check));
		if (check)
		{
			count++;
			check += ft_strlen(s2);
		}
	}
	return (count);
}

char		*ft_strreplace(char *s1, char *old, char *new)
{
	int		count;
	char	*cmd_res;
	char	*cmd_ret;

	if ((count = ft_strcount(s1, old)))
	{
		cmd_res = ft_strnew(ft_strlen(s1) + (ft_strlen(new) * count)
				- (ft_strlen(old) * count));
		cmd_ret = cmd_res;
		while (*s1 != '\0')
		{
			if (ft_strnstr(s1, old, ft_strlen(old)))
			{
				ft_strcpy(cmd_res, new);
				cmd_res += ft_strlen(new);
				s1 += ft_strlen(old);
				continue ;
			}
			*cmd_res = *s1;
			cmd_res++;
			s1++;
		}
		return (cmd_ret);
	}
	return (s1);
}
