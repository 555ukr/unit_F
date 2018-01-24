/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_non.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:35:51 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 17:32:08 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_non(t_form *collect)
{
	char	*output;
	char	pad;

	if (collect->zero == 1 && collect->minus == 1)
		collect->zero = 0;
	pad = (collect->zero == 0 ? ' ' : '0');
	output = ft_strdup("%");
	output = width_f(collect, output, pad);
	if (collect->type != '%')
		output[ft_strlen(output) - 1] = '\0';
	ft_putstr(output);
	free(output);
	return (ft_strlen(output));
}
