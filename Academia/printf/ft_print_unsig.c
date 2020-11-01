/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:58:41 by pserrano          #+#    #+#             */
/*   Updated: 2020/11/01 14:28:40 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	caseu_minus_prec(char *p, int i, int tam_num, t_list *f)
{
	p = print_menos(i, p, f);
	if (i < 0)
	{
		if (f->precision > tam_num)
			tam_num--;
	}
	print_zero(f->precision - tam_num, f);
	print_conversion_str(p, f);
	if (i < 0 && f->precision > tam_num)
		print_space(f->width - f->precision - 1, f);
	else if (i >= 0 && f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else if (f->precision < tam_num)
		print_space((f->width - tam_num), f);
}

void	caseu_width_prec(int i, int tam_num, char *p, t_list *f)
{
	if (i < 0)
	{
		if (f->precision > tam_num)
			print_space(f->width - f->precision - 1, f);
		else
			print_space(f->width - tam_num, f);
	}
	else
	{
		if (tam_num > f->precision)
			print_space(f->width - tam_num, f);
		else
			print_space(f->width - f->precision, f);
	}
	p = print_menos(i, p, f);
	if (i < 0)
		tam_num--;
	print_zero(f->precision - tam_num, f);
	print_conversion_str(p, f);
}

void	caseu_minus(char *p, int tam_num, int i, t_list *f)
{
	if (f->precision == 0 && i == 0)
		print_space(f->width, f);
	else
	{
		print_conversion_str(p, f);
		print_space((f->width - tam_num), f);
	}
}

void	caseu_width(char *p, int tam_num, int i, t_list *f)
{
	if (f->precision == 0 && i == 0)
		print_space(f->width, f);
	else
	{
		print_space((f->width - tam_num), f);
		print_conversion_str(p, f);
	}
}

void	print_unsigned(t_list *f)
{
	long long int			i;
	int						tam_num;
	char					*p;

	i = va_arg(f->ap, unsigned long int);
	p = i == -1 ? (ft_itoa(4294967295)) : (ft_itoa(i));
	tam_num = ft_strlen(p);
	if ((f->zero > 0) && (f->precision > 0))
		caseu_zero_prec(p, tam_num, f);
	else if (f->minus > 0 && f->precision <= 0)
		caseu_minus(p, tam_num, i, f);
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
		caseu_zero_o_prec(p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
		caseu_width(p, tam_num, i, f);
	else if (f->minus > 0 && f->precision > 0)
		caseu_minus_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		caseu_width_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_conversion_str(p, f);
	free(p);
}
