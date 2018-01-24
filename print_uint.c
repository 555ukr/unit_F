/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:54:50 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 17:04:25 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*length_uint(unsigned long long num)
{
	char	*copy;
	char	*output;

	output = NULL;
	if (num <= 2147483647)
		output = ft_itoa((int)num);
	else
		while (num)
		{
			copy = ft_itoa(num % 1000000000);
			output = ft_stradd(output, copy);
			num = num / 1000000000;
			free(copy);
		}
	return (output);
}

static char		*plus_uf(t_form *collect, unsigned long long num)
{
	char	*output;

	if (collect->space && (collect->plus || collect->preci))
		collect->space = 0;
	output = ((num == 0 && collect->preci && !collect->preci_value) ?
				ft_memalloc(1) : length_uint(num));
	return (output);
}

int				print_uint(t_form *collect, va_list ap)
{
	char				*output;
	char				pad;
	unsigned long long	num;

	if (collect->length_j || collect->length_ll || collect->length_z)
		num = va_arg(ap, unsigned long long);
	else if (collect->length_l || collect->type == 'U')
		num = (unsigned long)va_arg(ap, unsigned long long);
	else if (collect->length_h)
		num = (unsigned short)va_arg(ap, unsigned long long);
	else if (collect->length_hh)
		num = (unsigned char)va_arg(ap, unsigned long long);
	else
		num = va_arg(ap, unsigned int);
	if ((collect->zero == 1 && collect->minus == 1) || collect->preci)
		collect->zero = 0;
	pad = (collect->zero == 0 ? ' ' : '0');
	output = plus_uf(collect, num);
	output = preci_f(collect, output);
	output = width_f(collect, output, pad);
	ft_putstr(output);
	free(output);
	return (ft_strlen(output));
}
