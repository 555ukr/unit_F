/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:30:23 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 17:49:31 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		zero_f(t_form *collect)
{
	collect->flag = 0;
	collect->width = 0;
	collect->preci = 0;
	collect->lenth = 0;
	collect->plus = 0;
	collect->minus = 0;
	collect->hash = 0;
	collect->space = 0;
	collect->zero = 0;
	collect->width_value = 0;
	collect->preci_value = 0;
	collect->length = 0;
	collect->length_h = 0;
	collect->length_hh = 0;
	collect->length_l = 0;
	collect->length_ll = 0;
	collect->length_j = 0;
	collect->length_z = 0;
	collect->type = 0;
}

static int		attention(const char *format, va_list ap, int *rtn)
{
	t_form	*collect;
	int		back;

	if (!(collect = (t_form *)malloc(sizeof(t_form))))
		return (0);
	zero_f(collect);
	back = parsing(format + 1, collect);
	*rtn = print_f(collect, ap);
	free(collect);
	return (back + 1);
}

int				ft_printf(const char *format, ...)
{
	int		i;
	va_list ap;
	int		back;
	int		back_final;

	i = -1;
	back_final = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i = i + attention(&format[i], ap, &back) - 1;
			back_final = back_final + back;
		}
		else
		{
			ft_putchar(format[i]);
			back_final++;
		}
	}
	va_end(ap);
	return (back_final);
}
