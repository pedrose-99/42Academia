/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 09:12:57 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:27:49 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_list *f)
{
	f->cont = 0;
	f->spec = -1;
	f->minus = -1;
	f->argum = -1;
	f->precision = -1;
	f->width = -1;
	f->zero = -1;
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's'
		|| c == 'u' || c == 'x' || c == '%' || c == 'X'
		|| c == 'p')
		return (1);
	else
		return (0);
}

char	*ft_case_point(char *format_string, t_list *f)
{
	if (*format_string == '*')
		f->precision = va_arg(f->ap, int);
	else
		f->precision = ft_atoi(format_string);
	if (!is_specifier(*format_string))
	{
		while (!is_specifier(*(format_string + 1)))
			format_string++;
	}
	return (format_string);
}

char	*ft_store_data(char *format_string, t_list *f)
{
	while (!is_specifier(*format_string))
	{
		if (*format_string == '0')
			f->zero = 1;
		else if (*format_string == '-')
		{
			f->minus = 1;
		}
		else if (ft_is_num(*format_string))
		{
			f->width = ft_atoi(format_string);
			while (ft_is_num(*(format_string + 1)))
				format_string++;
		}
		else if (*format_string == '*')
		{
			f->width = va_arg(f->ap, int);
			f->argum = 1;
		}
		else if (*(format_string++) == '.')
			format_string = ft_case_point(format_string, f);
		if (!is_specifier(*format_string))
			format_string++;
	}
	return (format_string);
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
