/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:22:20 by pserrano          #+#    #+#             */
/*   Updated: 2020/11/01 14:48:33 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_list *f)
{
	char	i;

	if (f->spec == 'c')
		i = va_arg(f->ap, int);
	else
		i = '%';
	if ((f->zero > 0 && f->precision < 0)
		|| (f->width > 0 && f->precision < 0 && f->minus < 0))
		casec_zero_or_width(i, f);
	else if (f->minus > 0)
	{
		if (i == 0)
			ft_putchar('\0', f);
		else
			ft_putchar(i, f);
		print_space((f->width - 1), f);
	}
	else if (f->minus < 0 && f->width < 0)
	{
		if (i == 0)
			ft_putchar('\0', f);
		else
			ft_putchar(i, f);
	}
}

void	casec_zero_or_width(char i, t_list *f)
{
	if (f->zero > 0 && f->spec == '%')
		print_zero(f->width - 1, f);
	else
		print_space(f->width - 1, f);
	if (i == 0)
		ft_putchar('\0', f);
	else
		ft_putchar(i, f);
}

void	caseint_zero_o_prec(int i, char *p, int tam_num, t_list *f)
{
	p = print_menos(i, p, f);
	if (f->precision > 0)
	{
		if (i < 0)
			tam_num--;
		print_zero(f->precision - tam_num, f);
	}
	else
		print_zero(f->width - tam_num, f);
	print_conversion_str(p, f);
}

void	caseint_zero_prec(int i, int tam_num, char *p, t_list *f)
{
	if (f->precision < tam_num)
	{
		print_space(f->width - tam_num, f);
		if (f->precision > tam_num)
			tam_num--;
	}
	else if (i < 0)
		print_space(f->width - f->precision - 1, f);
	else
		print_space(f->width - f->precision, f);
	if (i < 0)
	{
		p = print_menos(i, p, f);
		tam_num = tam_num - 1;
	}
	print_zero(f->precision - tam_num, f);
	print_conversion_str(p, f);
}
