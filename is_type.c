/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 21:27:38 by dkalashn          #+#    #+#             */
/*   Updated: 2017/12/27 21:39:51 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	is_type(char c, t_form *collect)
{
	if (c == 'i' || c == 'd' || c == 's' || c == 'S' || c == 'p' || c == 'D' ||
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
			c == 'X' || c == 'c' || c == 'C' || c == '%')
		collect->type = c;
	else
		return (0);
	return (1);
}
