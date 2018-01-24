/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:57:53 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 17:14:01 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*hash_f(t_form *collect, char *output)
{
	if (!collect->hash)
		return (output);
	return (ft_stradd(output, "0"));
}

static char		*plus_uf(t_form *collect, unsigned long long num)
{
	char	*output;

	if (collect->space && (collect->plus || collect->preci))
		collect->space = 0;
	output = ((num == 0 && collect->preci && !collect->preci_value)
				? ft_memalloc(1) : ft_itoa_base(num, 8));
	if (output[0] != '0')
		output = hash_f(collect, output);
	return (output);
}

int				print_octal(t_form *collect, va_list ap)
{
	char				*output;
	char				pad;
	unsigned long long	num;

	if (collect->length_j || collect->length_ll || collect->length_z)
		num = va_arg(ap, unsigned long long);
	else if (collect->length_l || collect->type == 'O')
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
