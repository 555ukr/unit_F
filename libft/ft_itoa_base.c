/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:16:36 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/18 15:50:41 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long value, int base)
{
	int					count;
	char				*res;
	unsigned long long	nbr;
	char				*poll;

	if (base < 2 || base > 16)
		return (NULL);
	poll = "0123456789abcdef";
	nbr = value;
	count = 1;
	while (nbr / base)
	{
		count++;
		nbr = nbr / base;
	}
	if (!(res = ft_strnew(count)))
		return (NULL);
	while (count)
	{
		res[count - 1] = poll[value % base];
		value = value / base;
		count--;
	}
	return (res);
}
