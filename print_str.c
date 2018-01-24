/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:06:17 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/24 13:19:16 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*union_str(wchar_t *org)
{
	int		i;
	char	*output;
	char	*str1;
	char	*str2;

	if (org[0])
		output = ft_putchar_uni_split(org[0]);
	else
		return (ft_memalloc(1));
	i = 0;
	while (org[++i])
	{
		str2 = ft_putchar_uni_split(org[i]);
		str1 = ft_strjoin(output, str2);
		free(output);
		free(str2);
		output = str1;
	}
	return (output);
}

static int	print_str_uni(t_form *collect, va_list ap)
{
	wchar_t	*org;
	char	*output;
	char	*copy;
	int		pad;

	collect->type = 's';
	org = va_arg(ap, wchar_t *);
	if (!org)
		output = ft_strdup("(null)");
	else
		output = union_str(org);
	if (collect->zero == 1 && collect->minus == 1)
		collect->zero = 0;
	pad = (collect->zero == 0 ? ' ' : '0');
	if (collect->preci && (int)ft_strlen(output) > collect->preci_value)
	{
		copy = ft_strsub(output, 0, collect->preci_value);
		free(output);
		output = copy;
	}
	output = width_f(collect, output, pad);
	ft_putstr(output);
	free(output);
	return (ft_strlen(output));
}

int			print_str(t_form *collect, va_list ap)
{
	char	*output;
	char	pad;
	char	*copy;

	if (collect->type == 'S' || (collect->length_l && collect->type == 's'))
		return (print_str_uni(collect, ap));
	copy = (va_arg(ap, char *));
	if (!copy)
		output = ft_strdup("(null)");
	else
		output = ft_strdup(copy);
	if (collect->zero == 1 && collect->minus == 1)
		collect->zero = 0;
	pad = (collect->zero == 0 ? ' ' : '0');
	if (collect->preci && (int)ft_strlen(output) > collect->preci_value)
	{
		copy = ft_strsub(output, 0, collect->preci_value);
		free(output);
		output = copy;
	}
	output = width_f(collect, output, pad);
	ft_putstr(output);
	free(output);
	return (ft_strlen(output));
}
