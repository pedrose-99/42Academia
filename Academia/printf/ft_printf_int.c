/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:59:54 by pserrano          #+#    #+#             */
/*   Updated: 2020/10/26 12:20:06 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	print_cosita(p, f);
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
	print_cosita(p, f);
}

void	caseint_minus_prec(int i, int tam_num, char *p, t_list *f)
{
	p = print_menos(i, p, f);
	if (i < 0)
	{
		if (f->precision > tam_num)
			tam_num--;
	}
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
	if (i < 0 && f->precision > tam_num)
		print_space(f->width - f->precision - 1, f);
	else if (i >= 0 && f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else if (f->precision < tam_num)
		print_space((f->width - tam_num), f);
}

void	caseint_width_prec(int i, int tam_num, char *p, t_list *f)
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
	print_cosita(p, f);
}

void	caseint_minus(int i, int tam_num, char *p, t_list *f)
{
	if (f->precision == 0 && i == 0)
		print_space(f->width, f);
	else
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
}

void	caseint_width(int i, int tam_num, char *p, t_list *f)
{
	if (f->precision == 0 && i == 0)
		print_space(f->width, f);
	else
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
}

void	print_int(t_list *f)
{
	int		i;
	int		tam_num;
	char	*p;

	i = va_arg(f->ap, int);
	p = ft_itoa(i); 
	tam_num = ft_strlen(p);
	if (f->precision == 0 && i == 0 && f->width < 0 && f->minus < 0)
		ft_printf("%s", "");
	else if ((f->zero > 0) && (f->precision > 0))
		caseint_zero_prec(i, tam_num, p, f);
	else if (f->minus > 0 && f->precision <= 0)
		caseint_minus(i, tam_num, p, f);
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
		caseint_zero_o_prec(i, p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
		caseint_width(i, tam_num, p, f);
	else if (f->minus > 0 && f->precision > 0)
		caseint_minus_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		caseint_width_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width < 0 && f->precision <= 0)
		print_cosita(p, f);
	free (p);
}
