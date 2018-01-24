/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:52:08 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 17:46:35 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_stradd(char *src, char *str)
{
	char	*rtn;

	if (!str)
		return (src);
	if (!src)
		return (ft_strdup(str));
	rtn = ft_strjoin(str, src);
	free(src);
	return (rtn);
}

char		*length_int(long long num)
{
	char	*copy;
	char	*output;
	int		sign;

	sign = (num < 0 ? -1 : 1);
	output = NULL;
	if (num >= -2147483648 && num <= 2147483647)
		output = ft_itoa((int)num);
	else
		while (num)
		{
			if (num / 1000000000 == 0 && sign == -1)
				sign = 1;
			copy = ft_itoa(num % 1000000000 * sign);
			output = ft_stradd(output, copy);
			num = num / 1000000000;
			free(copy);
		}
	return (output);
}
