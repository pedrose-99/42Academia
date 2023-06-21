/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:36:24 by pserrano          #+#    #+#             */
/*   Updated: 2020/11/01 14:09:55 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	caseh_width(char *p, int i, int tam_num, t_list *f)
{
	if (f->precision == 0 && i == 0)
		print_space(f->width, f);
	else
	{
		print_space((f->width - tam_num), f);
		print_conversion_str(p, f);
	}
}

void	caseh_zero_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision < tam_num)
		print_space(f->width - tam_num, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_conversion_str(p, f);
}

void	caseh_minus_prec(char *p, int i, int tam_num, t_list *f)
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

void	caseh_width_prec(char *p, int i, int tam_num, t_list *f)
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

void	print_hexa(t_list *f)
{
	unsigned int	i;
	int				tam_num;
	char			*p;

	i = va_arg(f->ap, unsigned int);
	p = trans_hex(i, f->spec);
	tam_num = ft_strlen(p);
	if (f->precision == 0 && i == 0 && f->width < 0 && f->minus < 0)
		ft_printf("%s", "");
	else if ((f->zero > 0) && (f->precision > 0))
		caseh_zero_prec(p, tam_num, f);
	else if (f->minus > 0 && f->precision <= 0)
		caseh_minus(p, i, tam_num, f);
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
		caseh_zero_o_prec(p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
		caseh_width(p, i, tam_num, f);
	else if (f->minus > 0 && f->precision > 0)
		caseh_minus_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		caseh_width_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width < 0 && f->precision <= 0)
		print_conversion_str(p, f);
	free(p);
}
