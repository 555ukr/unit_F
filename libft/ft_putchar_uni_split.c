/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:35:38 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/24 13:53:25 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nbr_bit(unsigned int c)
{
	unsigned int	nbr;
	int				count;

	count = 1;
	nbr = c;
	while (nbr / 2)
	{
		count++;
		nbr = nbr / 2;
	}
	return (count);
}

static char			*add2_f(unsigned int c, char *output)
{
	unsigned char	o;
	unsigned char	oct;
	int				mask3;

	mask3 = 4034953344;
	output = ft_memalloc(5);
	o = ((c >> 18) << 29) >> 29;
	oct = (mask3 >> 24) | o;
	output[0] = (char)oct;
	o = ((c >> 12) << 26) >> 26;
	oct = ((mask3 << 8) >> 24) | o;
	output[1] = (char)oct;
	o = ((c >> 6) << 26) >> 26;
	oct = ((mask3 << 16) >> 24) | o;
	output[2] = (char)oct;
	o = (c << 26) >> 26;
	oct = ((mask3 << 24) >> 24) | o;
	output[3] = (char)oct;
	return (output);
}

static char			*add_f(unsigned int c, int bit, char *output)
{
	int				mask2;
	unsigned char	o;
	unsigned char	oct;

	mask2 = 14712960;
	if (bit <= 16 || MB_CUR_MAX < 4)
	{
		output = ft_memalloc(4);
		o = ((c >> 12) << 28) >> 28;
		oct = (mask2 >> 16) | o;
		output[0] = (char)oct;
		o = ((c >> 6) << 26) >> 26;
		oct = (mask2 << 16) >> 24 | o;
		output[1] = (char)oct;
		o = (c << 26) >> 26;
		oct = (mask2 << 24) >> 24 | o;
		output[2] = (char)oct;
		return (output);
	}
	else
		return (add2_f(c, output));
}

static char			*add_fun(unsigned int c, int bit, char *output, int mask1)
{
	unsigned char	o;
	unsigned		oct;

	if (bit <= 11 || MB_CUR_MAX < 3)
	{
		output = ft_memalloc(3);
		o = ((c >> 6) << 27) >> 27;
		oct = (mask1 >> 8) | o;
		output[0] = (char)oct;
		o = (c << 26) >> 26;
		oct = (mask1 << 24) >> 24 | o;
		output[1] = (char)oct;
		return (output);
	}
	else
		return (add_f(c, bit, output));
}

char				*ft_putchar_uni_split(unsigned int c)
{
	int				bit;
	int				mask1;
	char			*output;

	mask1 = 49280;
	bit = nbr_bit(c);
	output = NULL;
	if (bit <= 7 || MB_CUR_MAX < 2)
	{
		output = ft_memalloc(2);
		output[0] = (char)c;
		return (output);
	}
	else
		return (add_fun(c, bit, output, mask1));
}
