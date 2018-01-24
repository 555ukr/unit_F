/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:37:14 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/23 16:30:53 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	is_flag(char c, t_form *collect)
{
	if (c == '+')
		collect->plus = 1;
	else if (c == '-')
		collect->minus = 1;
	else if (c == ' ')
		collect->space = 1;
	else if (c == '#')
		collect->hash = 1;
	else if (c == '0')
		collect->zero = 1;
	else
		return (0);
	collect->flag = 1;
	return (1);
}

static int	is_width(const char *str, int i, t_form *collect)
{
	int res;
	int range;

	range = 1;
	if ((str[i] > '0' && str[i] <= '9') && (res = ft_atoi(&str[i])))
	{
		collect->width_value = res;
		collect->width = 1;
		while (res / 10 != 0)
		{
			range++;
			res = res / 10;
		}
		return (i + range);
	}
	return (0);
}

static int	is_preci(const char *str, int i, t_form *collect)
{
	int res;
	int range;

	range = 1;
	if (str[i] == '.')
	{
		collect->preci = 1;
		res = ft_atoi(&str[i + 1]);
		if (res > 0 || (str[i + 1] == '0'))
			collect->preci_value = res;
		else
			range--;
		while (res / 10 != 0)
		{
			range++;
			res = res / 10;
		}
		return (i + range + 1);
	}
	else
		return (0);
}

static int	is_length(const char *str, int i, t_form *collect)
{
	if (str[i])
	{
		if (ft_strncmp(&str[i], "hh", 2) == 0)
			collect->length_hh = 1;
		else if (str[i] == 'h')
			collect->length_h = 1;
		else if (ft_strncmp(&str[i], "ll", 2) == 0)
			collect->length_ll = 1;
		else if (str[i] == 'l')
			collect->length_l = 1;
		else if (str[i] == 'j')
			collect->length_j = 1;
		else if (str[i] == 'z')
			collect->length_z = 1;
		else
			return (0);
		collect->length = 1;
		if ((ft_strncmp(&str[i], "hh", 2) == 0) ||
				(ft_strncmp(&str[i], "ll", 2) == 0))
			return (i + 2);
	}
	return (i + 1);
}

int			parsing(const char *str, t_form *collect)
{
	int i;
	int	skip1;
	int skip2;
	int skip3;
	int skip4;

	i = 0;
	while (!(is_type(str[i], collect)))
	{
		if ((skip1 = is_flag(str[i], collect)))
			i++;
		if ((skip2 = is_width(str, i, collect)))
			i = skip2;
		if ((skip3 = is_preci(str, i, collect)))
			i = skip3;
		if ((skip4 = is_length(str, i, collect)))
			i = skip4;
		if (!skip1 && !skip2 && !skip3 && !skip4)
		{
			collect->type = (collect->type == 0 ? str[i] : collect->type);
			break ;
		}
	}
	return (i + 1);
}
