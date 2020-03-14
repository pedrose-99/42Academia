/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/10 12:30:34 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_putchar(char c, t_list *f)
{
	write(1, &c, 1);
	f->cont++;
}

int		ft_printf(const char *cosa, ...)
{
	t_list	*f;

	//if(!(f = malloc(sizeof(t_list) *  )))
	//	return (-1);
	init_struct(f);
	va_start(f->ap, cosa);
	while (cosa[f->pos])
	{
		if (*cosa == '%')
			ft_store_data(cosa, f);
		else
		{
			ft_putchar(*cosa);
			cosa++;
			f->cont++;
		}
	}

}*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_cosita(char *p)
{
	while (*p)
	{
		ft_putchar(*p);
		p++;
	}
	//free(p);
}

int		main(void)
{
	printf("%03d", 22);
	//print_spozero(22, 6, 6);
	//ft_printf("f",);
}

/*void	print_int(t_list *f)
{
	int		i;
	int		tam_num;
	char	*p;

	i = va_arg(f->ap, int);
	p = ft_itoa(i);
	tam_num = ft_strlen(p);
	if (f->zero && f->precision && (!(f->minus)))
		print_spozero(p, tam_num, f);
	else if ((f->minus > 0) && (f->precision > 0) || (f->zero > 0))
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
		print_space((f->width - f->precision), f);
	}
	else if (f->minus > 0)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if (f->zero > 0)
	{
		print_zero((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->precision  > 0)
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
	}
	else if ((f->zero < 0) && ((f->minus < 0)) && (f->width > 0))
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if ((f->zero < 0) && ((f->minus < 0)) && (f->precision > 0))
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
	}
}
si un unsigned int es negativo resta el mayor unsigned int 4,294,967,295+1 -(el numero que has puesto)
ej = %u, -1 ==== 4,294,967,295.
si 05.0d, 22 === (   22)
si 05.1d, 22 === (   22) si precision < long(num) te rellena con espacios print num
si 05.3d, 22 === (  022) si precision > long(num) pero precision < width == (espacios = width -(precision -long(num)) zeros = precision - long(num) print num
si 05.10d, 22 === (0000000022) si precision > width y > long(num) zeros = precision - long num*/
