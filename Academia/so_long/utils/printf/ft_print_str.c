/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:22:31 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:14:34 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_string(char *s)
{
	if (s)
		return (ft_strdup(s));
	else
		return (ft_strdup("(null)"));
}

void	casestr_zero_o_width(char *i, int tam_str, t_list *f)
{
	if (f->zero > 0)
		print_zero(f->width - tam_str, f);
	else
		print_space(f->width - tam_str, f);
	print_conversion_str(i, f);
}

void	casestr_minus(char *i, int tam_str, t_list *f)
{
	print_conversion_str(i, f);
	print_space((f->width - tam_str), f);
}

void	casestr_precision(char *i, int tam_str, t_list *f)
{
	if (tam_str < f->precision)
		print_string(i, tam_str, f);
	else
		print_string(i, f->precision, f);
}

void	print_str(t_list *f)
{
	char	*i;
	int		tam_str;

	i = va_arg(f->ap, char *);
	i = handle_string(i);
	tam_str = ft_strlen(i);
	if ((f->zero > 0 && f->precision < 0)
		|| (f->width > 0 && f->precision < 0 && f->minus < 0))
		casestr_zero_o_width(i, tam_str, f);
	else if (f->precision == 0)
		print_space(f->width, f);
	else if (f->minus > 0 && f->precision < 0)
		casestr_minus(i, tam_str, f);
	else if ((f->zero > 0 && f->precision > 0)
		|| (f->width > 0 && f->precision > 0 && f->minus < 0))
		casestr_zero_precs(i, tam_str, f);
	else if (f->minus > 0 && f->precision > 0)
		casestr_minus_precs(i, tam_str, f);
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_conversion_str(i, f);
	else if (f->minus < 0 && f->width < 0 && f->precision > 0)
		casestr_precision(i, tam_str, f);
	free(i);
}
