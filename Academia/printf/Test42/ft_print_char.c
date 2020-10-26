/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:22:20 by pserrano          #+#    #+#             */
/*   Updated: 2020/10/26 11:25:29 by pserrano         ###   ########.fr       */
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
	if ((f->zero > 0 && f->precision < 0) || (f->width > 0 && f->precision < 0 && f->minus < 0))
	{
		print_space(f->width - 1, f);
		if (i == 0)
			ft_putchar('\0', f);
		else
			ft_putchar(i, f);
	}
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
