/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 22:02:26 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 17:35:12 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char					*hash_hf(t_form *collect, char *output,
										unsigned long long num)
{
	if (!collect->hash)
		return (output);
	if ((collect->type == 'x' || collect->type == 'X') && num != 0)
		return (ft_stradd(output, "0x"));
	else if (collect->type == 'p')
		return (ft_stradd(output, "0x"));
	return (output);
}

static char					*plus_hf(t_form *collect, unsigned long long num)
{
	char	*output;

	if (collect->space && (collect->plus || collect->preci))
		collect->space = 0;
	output = ((num == 0 && collect->preci && !collect->preci_value) ?
				ft_memalloc(1) : ft_itoa_base(num, 16));
	return (output);
}

static unsigned long long	get_num_h(t_form *collect, va_list ap)
{
	unsigned long long num;

	if (collect->length_j || collect->length_ll || collect->length_z)
		num = va_arg(ap, unsigned long long);
	else if (collect->length_l)
		num = (unsigned long)va_arg(ap, unsigned long long);
	else if (collect->length_h)
		num = (unsigned short)va_arg(ap, unsigned long long);
	else if (collect->length_hh)
		num = (unsigned char)va_arg(ap, unsigned long long);
	else
		num = va_arg(ap, unsigned int);
	return (num);
}

int							print_hex(t_form *collect, va_list ap)
{
	char				*output;
	char				pad;
	unsigned long long	num;
	int					i;

	num = get_num_h(collect, ap);
	if ((collect->zero == 1 && collect->minus == 1) || collect->preci)
		collect->zero = 0;
	pad = (collect->zero == 0 ? ' ' : '0');
	output = plus_hf(collect, num);
	output = preci_f(collect, output);
	output = hash_hf(collect, output, num);
	output = width_hf(collect, output, pad);
	i = -1;
	while (collect->type == 'X' && output[++i])
		output[i] = ft_toupper(output[i]);
	ft_putstr(output);
	free(output);
	return (ft_strlen(output));
}
