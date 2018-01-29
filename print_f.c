/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 21:00:14 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/26 16:43:14 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char				*preci_f(t_form *prs, char *output)
{
	int		len;
	char	*copy;
	char	*zero;
	int		dif;
	int		i;

	len = ft_strlen(output);
	i = ((output[0] == '+' || output[0] == '-') ? 1 : 0);
	dif = (prs->preci_value - len + i);
	if ((prs->preci && (prs->preci_value == 0 || dif <= 0)) || !prs->preci)
		return (output);
	dif = (dif < 0 ? dif * (-1) : dif);
	zero = ft_strnew(dif + i);
	zero[0] = (i == 1 ? output[0] : '0');
	while (zero && dif--)
		zero[dif + i] = '0';
	copy = ft_strjoin(zero, (output + i));
	free(zero);
	free(output);
	return (copy);
}

static char			*plus_f(t_form *collect, long long num)
{
	char	*copy;
	char	*output;

	output = ((num == 0 && collect->preci && !collect->preci_value) ?
				ft_memalloc(1) : length_int(num));
	if (collect->plus && num >= 0)
	{
		copy = ft_strjoin("+", output);
		free(output);
		return (copy);
	}
	return (output);
}

static long long	get_num(t_form *collect, va_list ap)
{
	long long num;

	if (collect->length_j || collect->length_ll || collect->length_z)
		num = va_arg(ap, long long);
	else if (collect->length_l || collect->type == 'D')
		num = (long)va_arg(ap, long long);
	else if (collect->length_h)
		num = (short)va_arg(ap, long long);
	else if (collect->length_hh)
		num = (char)va_arg(ap, long long);
	else
		num = va_arg(ap, int);
	return (num);
}

static int			print_int(t_form *collect, va_list ap)
{
	char				*output;
	char				pad;
	long long			num;

	num = get_num(collect, ap);
	if ((collect->zero == 1 && collect->minus == 1) || collect->preci)
		collect->zero = 0;
	pad = (collect->zero == 0 ? ' ' : '0');
	output = plus_f(collect, num);
	output = preci_f(collect, output);
	if (collect->space && output[0] != '-' && !collect->plus)
		output = ft_stradd(output, " ");
	output = width_f(collect, output, pad);
	ft_putstr(output);
	free(output);
	return (ft_strlen(output));
}

int					print_f(t_form *collect, va_list ap)
{
	if (collect->type == 'i' || collect->type == 'd' || collect->type == 'D')
		return (print_int(collect, ap));
	else if (collect->type == 'u' || collect->type == 'U')
		return (print_uint(collect, ap));
	else if (collect->type == 'c' || collect->type == 'C')
		return (print_char(collect, ap));
	else if (collect->type == 'o' || collect->type == 'O'
			|| collect->type == 'b')
		return (print_octal(collect, ap));
	else if (collect->type == 'x' || collect->type == 'X')
		return (print_hex(collect, ap));
	else if (collect->type == 'p')
		return (print_p(collect, ap));
	else if (collect->type == 's' || collect->type == 'S')
		return (print_str(collect, ap));
	else if (collect->type == '%')
		return (print_non(collect));
	return (0);
}
