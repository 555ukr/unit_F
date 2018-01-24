/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 22:10:27 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/22 17:05:05 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_form
{
	unsigned int	flag : 1;
	unsigned int	width : 1;
	unsigned int	preci : 1;
	unsigned int	lenth : 1;
	unsigned int	plus : 1;
	unsigned int	minus : 1;
	unsigned int	hash : 1;
	unsigned int	space : 1;
	unsigned int	zero : 1;
	int				width_value;
	int				preci_value;
	unsigned int	length : 1;
	unsigned int	length_h : 1;
	unsigned int	length_hh : 1;
	unsigned int	length_l : 1;
	unsigned int	length_ll : 1;
	unsigned int	length_j : 1;
	unsigned int	length_z : 1;
	char			type;
}					t_form;
int					ft_printf(const char *format, ...);
int					parsing(const char *str, t_form *collect);
int					is_type(char c, t_form *collect);
int					print_f(t_form *collect, va_list ap);
char				*length_int(long long num);
int					print_uint(t_form *collect, va_list ap);
char				*preci_f(t_form *prs, char *output);
char				*width_f(t_form *prs, char *ot, char pad);
int					print_char(t_form *collect, va_list ap);
char				*ft_stradd(char	*src, char *str);
int					print_octal(t_form *collect, va_list ap);
int					print_hex(t_form *collect, va_list ap);
char				*width_hf(t_form *prs, char *ot, char pad);
char				*width_hxf(t_form *prs, char *ot, char pad);
int					print_p(t_form *collect, va_list ap);
int					print_non(t_form *collect);
int					print_str(t_form *collect, va_list ap);

#endif
