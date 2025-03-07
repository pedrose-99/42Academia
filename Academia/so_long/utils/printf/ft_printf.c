/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:19:31 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
	return (size);
}

int	ft_count_nb(long int nb)
{
	long int		count;
	unsigned int	c;

	c = 0;
	count = 0;
	if (nb < 0)
	{
		c = nb * -1;
		count++;
	}
	if (nb > 0)
		c = nb;
	while (c >= 10)
	{
		c = c / 10;
		count++;
	}
	if (c < 10)
		count++;
	return (count);
}

void	print_all(t_list *f)
{
	char	c;

	c = f->spec;
	if (c == 'd' || c == 'i')
		print_int(f);
	else if (c == 'c')
		print_char(f);
	else if (c == 's')
		print_str(f);
	else if (c == '%')
		print_char(f);
}

int	ft_printf(const char *format_string, ...)
{
	t_list	f;

	init_struct(&f);
	va_start(f.ap, format_string);
	while (*format_string)
	{
		if (*format_string == '%')
		{
			format_string = ft_store_data((char *)(format_string + 1), &f);
			ft_store_data_def(&f);
			f.spec = *(format_string++);
			print_all(&f);
		}
		else
		{
			ft_putchar(*format_string, &f);
			format_string++;
		}
	}
	va_end(f.ap);
	return (f.cont);
}
