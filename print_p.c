/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:12:45 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 13:00:10 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_p(t_form *collect, va_list ap)
{
	collect->length = 1;
	collect->length_ll = 1;
	collect->hash = 1;
	return (print_hex(collect, ap));
}
