/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:59:32 by dkalashn          #+#    #+#             */
/*   Updated: 2018/01/23 21:14:11 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*width_add_f(char *output, char pad, int dif)
{
	char	*copy;
	char	*pading;

	pading = ft_strnew(dif);
	while (pading && dif--)
		pading[dif] = pad;
	copy = ft_strjoin(output, pading);
	free(pading);
	return (copy);
}

char		*width_f(t_form *prs, char *ot, char pad)
{
	int		len;
	int		i;
	char	*pading;
	int		dif;
	char	*copy;

	len = ft_strlen(ot);
	dif = prs->width_value - len;
	if (prs->width == 0 || prs->width_value == 0 || dif <= 0)
		return (ot);
	i = ((ot[0] == '+' || ot[0] == '-' || ot[0] == ' ') && pad == '0' &&
			prs->type != 's' ? 1 : 0);
	if (prs->width_value > len && !prs->minus)
	{
		pading = ft_strnew(dif + i);
		pading[0] = (i == 1 ? ot[0] : pad);
		while (pading && dif--)
			pading[dif + i] = pad;
		copy = ft_strjoin(pading, (ot + i));
		free(pading);
	}
	else
		copy = width_add_f(ot, pad, dif);
	free(ot);
	return (copy);
}

char		*width_hf(t_form *prs, char *ot, char pad)
{
	int		len;
	int		i;
	char	*pading;
	int		dif;
	char	*copy;

	len = ft_strlen(ot);
	dif = prs->width_value - len;
	if (prs->width == 0 || prs->width_value == 0 || dif <= 0)
		return (ot);
	i = ((!ft_strncmp(ot, "0x", 2)) && pad == '0' ? 2 : 0);
	if (prs->width_value > len && !prs->minus)
	{
		pading = ft_strnew(dif + i);
		(i == 2 ? ft_strncpy(pading, "0x", 2) : 0);
		while (pading && dif--)
			pading[dif + i] = pad;
		copy = ft_strjoin(pading, (ot + i));
		free(pading);
	}
	else
		copy = width_add_f(ot, pad, dif);
	free(ot);
	return (copy);
}
