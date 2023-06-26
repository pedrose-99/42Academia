/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:46:48 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:21:05 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	caseh_minus(char *p, int i, int tam_num, t_list *f)
{
	if (f->precision == 0 && i == 0)
		print_space(f->width, f);
	else
	{
		print_conversion_str(p, f);
		print_space((f->width - tam_num), f);
	}
}

void	caseu_zero_o_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision > 0)
		print_zero(f->precision - tam_num, f);
	else
		print_zero(f->width - tam_num, f);
	print_conversion_str(p, f);
}

void	caseu_zero_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision < tam_num)
		print_space(f->width - tam_num, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_conversion_str(p, f);
}
