/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/03 14:46:23 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

 int		ft_typeflag1152(char c)
{
	if (cosa[i] == 'd')
	{
		i++;
		p = va_arg(ap, int);
	}
}

int		ft_case_first_num(t_list *f)
{
	va_list next;
	int		num; 
	int		tam;
	char	*numdef;


	va_copy(next, ap);
	if (cosa[f->pos++] == '0')
	{
		num = va_arg(next, int) 
		tam = ft_strlen(num);
		res = tam - cosa[f->pos];
		if (ft_isneg(num));
		{
			ft_putchar('-');
			res--;
		}
		while (res > 0)
		{
			ft_putchar('0');
			res--;
		}
		numfef = itoa((num);
		ft_putstr(numdef);
	}
	if (cosa[f->pos] == '-')
	{
		
	}
}

int		init_struct(t_list *f)
{
	f->cont = 0;
	f->flag= 0;
	f->len = 0;
	f->minus = 0;
	f->pos = 0;
	f->precision = 0;
	f->space = 0;
	f->width = 0;
	f->zero = 0;
	f->numspaces = 0;

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
int		main(void)
{
	printf("%d", printf("%-0d", 22));
	//ft_printf("f",);
}
