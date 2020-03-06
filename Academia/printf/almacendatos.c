/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almacendatos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 09:12:57 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/06 07:22:17 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_struct(t_list *f)
{
	f->cont = 0;
	f->spec = -1;
	f->len = 0;
	f->minus = -1;
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
			f->minus = 1;
		else if (ft_is_num(*cosa))
		{
			f->width = ft_atoi(cosa);
			while (ft_is_num(*(cosa + 1)))
				cosa++;
		}
		else if (*cosa == '*')
			f->width = va_arg(f->ap, int);
		else if (*(cosa++) == '.')
		{
			if (*cosa == '*')
				f->precision = va_arg(f->ap, int);
			else
				f->precision = ft_atoi(cosa);
			while (!is_specifier(*(cosa + 1)))
				cosa++;
		}
		cosa++;
	}
	return (cosa);
}

int ft_printf(const char *cosa, ...)
{
	t_list f;

	//if(!(f = malloc(sizeof(t_list) *  )))
	//	return (-1);
	init_struct(&f);
	va_start(f.ap, cosa);
	while (*cosa)
	{
		if (*cosa == '%')
		{
			cosa = ft_store_data((char*)(cosa + 1), &f);
			f.spec = *(cosa++);
			printf("%d\n", f.minus);
			printf("%d\n", f.zero);
			printf("%d\n", f.width);;
			printf("%d\n", f.precision);
		}
		else
		{
			ft_putchar(*cosa, &f);
			cosa++;
		}
	}
	return (1);
}

int main(void)
{
	//printf("hola %0*.f holabuenosdoas",100, 89.24567);
	ft_printf("%0-0.*f", 11);
}

/*
			printf("%d\n", f.minus
			printf("%d\n", f.zero);
			printf("%d\n", f.width);;
			printf("%d\n", f.precision);
*/