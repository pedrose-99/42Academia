/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:30:37 by pserrano          #+#    #+#             */
/*   Updated: 2020/11/01 14:19:58 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	casehp_width_prec(char *p, int i, int tam_num, t_list *f)
{
	if (i < 0)
		print_space(f->width - f->precision - 1, f);
	else
	{
		if (f->precision > tam_num)
			print_space(f->width - f->precision, f);
		else
			print_space(f->width - tam_num, f);
	}
	tam_num = tam_num - 2;
	p = print_hexap_prec(p, f);
	print_zero(f->precision - tam_num, f);
	print_conversion_str(p, f);
}

char	*trans_hexp(long long int i)
{
	long long int		i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 3;
	hex_char = "0123456789abcdef";
	i_copy = i;
	while (i_copy >= 16 && (i_copy /= 16))
		count++;
	i_copy = i;
	if (!(def = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	def[count] = '\0';
	while (i_copy > 15)
	{
		--count;
		def[count] = hex_char[i_copy % 16];
		i_copy /= 16;
	}
	def[--count] = hex_char[i_copy % 16];
	def = type_p(def);
	return (def);
}

void	casep_null(t_list *f)
{
	if (f->precision == 0 && f->width < 2)
	{
		print_conversion_str("0x", f);
		if (f->precision > 2)
			print_zero(f->precision, f);
	}
	else if (f->precision == 0)
	{
		print_space(f->width - 2, f);
		print_conversion_str("0x", f);
	}
	else
	{
		if (f->width > 2)
			print_space(f->width - 3, f);
		print_conversion_str("0x0", f);
		if (f->precision >= 2)
			print_zero(f->precision - 1, f);
	}
}

void	print_hexap(t_list *f)
{
	long int		i;
	int				tam_num;
	char			*p;

	i = va_arg(f->ap, long int);
	p = trans_hexp(i);
	tam_num = ft_strlen(p);
	if (i == 0)
		casep_null(f);
	else if ((f->zero > 0) && (f->precision > 0))
		caseh_zero_prec(p, tam_num, f);
	else if (f->minus > 0 && f->precision <= 0)
		casehp_minus(p, tam_num, f);
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
		caseh_zero_o_prec(p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
		casehp_width(p, tam_num, f);
	else if (f->minus > 0 && f->precision > 0)
		caseh_minus_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		casehp_width_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_conversion_str(p, f);
	free(p);
}
