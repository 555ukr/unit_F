/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:21:13 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/24 13:25:43 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		add_char_f(t_form *collect, char *output, int len, char pad)
{
	if (len >= collect->width_value)
	{
		ft_putchar(0);
		return (1);
	}
	if (collect->width_value >= 1)
		collect->width_value--;
	output = width_f(collect, output, pad);
	if (collect->minus)
	{
		ft_putchar(0);
		ft_putstr(output);
		free(output);
		return (ft_strlen(output) + 1);
	}
	ft_putstr(output);
	ft_putchar(0);
	free(output);
	return (ft_strlen(output) + 1);
}

static int		continue_f(t_form *collect, char *output, char pad)
{
	output = width_f(collect, output, pad);
	ft_putstr(output);
	free(output);
	return (ft_strlen(output));
}

int				print_char(t_form *collect, va_list ap)
{
	char				pad;
	unsigned int		uni;
	char				*output;
	int					len;

	uni = 0;
	len = 1;
	output = ft_memalloc(5);
	if (collect->zero == 1 && collect->minus == 1)
		collect->zero = 0;
	pad = (collect->zero == 0 ? ' ' : '0');
	if (!collect->length_l && collect->type == 'c')
	{
		uni = va_arg(ap, int);
		output[0] = (char)uni;
	}
	else
	{
		uni = va_arg(ap, unsigned int);
		len = ft_putchar_uni(uni, output);
	}
	if (uni)
		return (continue_f(collect, output, pad));
	return (add_char_f(collect, output, len, pad));
}
