/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/10/23 14:44:36 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int size;

	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
	return (size);
}

int		ft_count_nb(long int nb)
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

void	print_todos(t_list *f)
{
	char c;

	c = f->spec;
	if (c == 'd' || c == 'i')
		print_int(f);
	else if (c == 'u')
		print_unsigned(f);
	else if (c == 'x' || c == 'X')
		print_hexa(f);
	else if (c == 'p')
		print_hexap(f);
	else if (c == 'c')
		print_char(f);
	else if (c == 's')
		print_str(f);
	else if (c == '%')
		ft_putchar('%', f);
}

int		ft_printf(const char *cosa, ...)
{
	t_list f;

	init_struct(&f);
	va_start(f.ap, cosa);
	while (*cosa)
	{
		if (*cosa == '%')
		{
			cosa = ft_store_data((char*)(cosa + 1), &f);
			ft_store_data_def(&f);
			f.spec = *(cosa++);
			print_todos(&f);
		}
		else
		{
			ft_putchar(*cosa, &f);
			cosa++;
		}
	}
	return (f.cont);
}
