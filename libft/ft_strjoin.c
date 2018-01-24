/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:57:32 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 17:39:18 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s_1;
	int		s_2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s_1 = ft_strlen(s1);
	s_2 = ft_strlen(s2);
	res = (char *)malloc(s_1 + s_2 + 1);
	if (!res)
		return (NULL);
	return (ft_strcat(ft_strcpy(res, s1), s2));
}
