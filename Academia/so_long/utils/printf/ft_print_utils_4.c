/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:11:58 by pserrano          #+#    #+#             */
/*   Updated: 2020/11/01 14:13:26 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	casehp_minus(char *p, int tam_num, t_list *f)
{
	print_conversion_str(p, f);
	print_space((f->width - tam_num), f);
}

void	casehp_width(char *p, int tam_num, t_list *f)
{
	print_space((f->width - tam_num), f);
	print_conversion_str(p, f);
}

void	caseh_zero_o_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision > 0)
		print_zero(f->precision - tam_num, f);
	else
		print_zero(f->width - tam_num, f);
	print_conversion_str(p, f);
}

char	*type_p(char *def)
{
	int	p;

	p = 0;
	def[p] = '0';
	p++;
	def[p] = 'x';
	p++;
	return (def);
}

char	*print_hexap_prec(char *p, t_list *f)
{
	int i;

	i = 0;
	while (i < 2)
	{
		ft_putchar(*p, f);
		p++;
		i++;
	}
	return (p);
}
