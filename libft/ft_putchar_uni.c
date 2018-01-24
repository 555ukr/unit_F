/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:35:38 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/23 14:36:46 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			marazm(void)
{
	int mask3;

	mask3 = 4034953344;
	return (mask3);
}

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

static int			add2_f(unsigned int c, int mask3, char *output)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	unsigned char	oct;

	o4 = (c << 26) >> 26;
	o3 = ((c >> 6) << 26) >> 26;
	o2 = ((c >> 12) << 26) >> 26;
	o1 = ((c >> 18) << 29) >> 29;
	oct = (mask3 >> 24) | o1;
	output[0] = (char)oct;
	oct = ((mask3 << 8) >> 24) | o2;
	output[1] = (char)oct;
	oct = ((mask3 << 16) >> 24) | o3;
	output[2] = (char)oct;
	oct = ((mask3 << 24) >> 24) | o4;
	output[3] = (char)oct;
	return (4);
}

static int			add_f(unsigned int c, int bit, char *output)
{
	int				mask2;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	oct;

	mask2 = 14712960;
	if (bit <= 16 || MB_CUR_MAX < 4)
	{
		o3 = (c << 26) >> 26;
		o2 = ((c >> 6) << 26) >> 26;
		o1 = ((c >> 12) << 28) >> 28;
		oct = (mask2 >> 16) | o1;
		output[0] = (char)oct;
		oct = (mask2 << 16) >> 24 | o2;
		output[1] = (char)oct;
		oct = (mask2 << 24) >> 24 | o3;
		output[2] = (char)oct;
		return (3);
	}
	else
		return (add2_f(c, marazm(), output));
}

int					ft_putchar_uni(unsigned int c, char *output)
{
	int				bit;
	int				mask1;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	oct;

	mask1 = 49280;
	bit = nbr_bit(c);
	if (bit <= 7 || MB_CUR_MAX < 2)
	{
		output[0] = (char)c;
		return (1);
	}
	else if (bit <= 11 || MB_CUR_MAX < 3)
	{
		o2 = (c << 26) >> 26;
		o1 = ((c >> 6) << 27) >> 27;
		oct = (mask1 >> 8) | o1;
		output[0] = (char)oct;
		oct = (mask1 << 24) >> 24 | o2;
		output[1] = (char)oct;
		return (2);
	}
	else
		return (add_f(c, bit, output));
}
