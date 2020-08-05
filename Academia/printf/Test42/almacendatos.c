/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almacendatos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 09:12:57 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/24 23:16:33 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_struct(t_list *f)
{
	f->cont = 0;
	f->spec = -1;
	f->minus = -1;
	f->argum = -1;
	f->precision = -1;
	f->width = -1;
	f->zero = -1;
}

int is_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' ||
		c == 'u' || c == 'x' || c == '%' || c == 'X' || c == 'p')
		return (1);
	else
		return (0);
}

char 	*ft_store_data(char *cosa, t_list *f)
{
	while (!is_specifier(*cosa))
	{
		if (*cosa == '0')
			f->zero = 1;
		else if (*cosa == '-')
		{
			f->minus = 1;
		}
		else if (ft_is_num(*cosa))
		{
			f->width = ft_atoi(cosa);
			while (ft_is_num(*(cosa + 1)))
				cosa++;
		}
		else if (*cosa == '*')
		{
			f->width = va_arg(f->ap, int);
			f->argum = 1;

		}
		else if (*(cosa++) == '.')
		{
			if (*cosa == '*')
				f->precision = va_arg(f->ap, int);
			else
				f->precision = ft_atoi(cosa);
			if (!is_specifier(*cosa))
			{
				while (!is_specifier(*(cosa + 1)))
					cosa++;
			}
		}
		if (!is_specifier(*cosa))
		cosa++;
	}
	return (cosa);
}

void	ft_store_data_def(t_list *f)
{
	if (f->width < 0 && f->argum > 0)
	{
		f->minus = 1;
		f->width = f->width * (-1);
	}
	if (f->minus > 0)
		f->zero = -1;
}
