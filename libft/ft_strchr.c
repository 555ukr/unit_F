/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:16:34 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/09 18:56:48 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			res = &s[i];
			return ((char *)res);
		}
		i++;
	}
	if (c == '\0')
		res = &s[i];
	return ((char *)res);
}
