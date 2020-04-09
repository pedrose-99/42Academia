/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:59:54 by pserrano          #+#    #+#             */
/*   Updated: 2020/04/08 20:52:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_zero_o_prec(int i, char *p, int tam_num, t_list *f)
{
	p = print_menos(i, p, f);
	if (f->precision > 0)
		print_zero(f->precision - tam_num, f);
	else
		print_zero(f->width - tam_num, f);
	print_cosita(p, f);
}

void	case_zero_prec(int tam_num, char *p, t_list *f)
{
	if (f->precision < tam_num)
		print_space(f->width - tam_num, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	case_minus_prec(int i, int tam_num, char *p, t_list *f)
{
	p = print_menos(i, p, f);
	if (i < 0)
		tam_num--;
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
	if (i < 0 && f->precision > tam_num)
		print_space(f->width - f->precision - 1, f);
	else if (i > 0 && f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else if (f->precision < tam_num)
		print_space((f->width - tam_num), f);
}

void	case_width_prec(int i, int tam_num, char*p, t_list *f)
{
	if (i < 0)
		print_space(f->width - f->precision - 1, f);
	else
		print_space(f->width - f->precision, f);
	p = print_menos(i, p, f);
	if (i < 0)
		tam_num--;
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	print_int(t_list *f)
{
	int		i;
	int		tam_num;
	char	*p;

	i = va_arg(f->ap, int);
	p = ft_itoa(i);
	tam_num = ft_strlen(p);
	if ((f->zero > 0) && (f->precision > 0))
		case_zero_prec(tam_num, p, f);
	else if (f->minus > 0 && f->precision <= 0)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
			case_zero_o_prec(i, p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->minus > 0 && f->precision > 0)
		case_minus_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		case_width_prec(i, tam_num, p, f);
}

/*
		print_string(f);
	else if (f->spec == 'u')
		print_unsigned_int(f);
	else if (f->spec == 'x')
		print_hexa_minus(f);
	else if (f->spec == 'X')
		print_hexa_mayus(f);
	else if (f->spec == '%')
		print_porcentaje(f); //tener en cuenta las mismas cosas que la c(o eso cree raul)
}
int		main(void)
{
	//printf("%0-6.3dg\n", 22);
	//print_spozero(22, 6, 6);
	//ft_printf("%0-6.3d", 22);
	ft_printf("%-0*.3dFIN\n", 4, 42);
	ft_printf("%0*.1dFIN\n", 4, -42);
	ft_printf("%-2.3dFIN\n", 42);
	ft_printf("%*dFIN\n", 4, -42);
	ft_printf("%-04.1dFIN\n", 42);
	ft_printf("%-*.5dFIN\n", 7, -42);
	ft_printf("%*.5dFIN\n", 7, -42);
	ft_printf("%*.7dFIN\n", 5, 42);
	ft_printf("%0*dFIN\n", 4, -42);
	ft_printf("%-dFIN\n", 42);
	ft_printf("%-0dFIN\n", 42);
	ft_printf("%0dFIN\n", 42);
	ft_printf("%*dFIN\n", 1, 42); 
	ft_printf("%0*dFIN\n", 1, 42);
	ft_printf("%.1dFIN\n", 42);
	ft_printf("%-.1dFIN\n", 42);
	ft_printf("%-*.2dFIN\n", 2, 42);
		printf("hasta aqui\n");

	printf("%-0*.3dFIN\n", 4, 42);									
	printf("%0*.1dFIN\n", 4, -42);		
	printf("%-2.3dFIN\n", 42);			
	printf("%*dFIN\n", 4, -42);		
	printf("%-04.1dFIN\n", 42);			
	printf("%-*.5dFIN\n", 7, -42);
	printf("%*.5dFIN\n", 7, -42);
	printf("%*.7dFIN\n", 5, 42);
	printf("%0*dFIN\n", 4, -42);
	printf("%-dFIN\n", 42);
	printf("%-0dFIN\n", 42);
	printf("%0dFIN\n", 42);
	printf("%*dFIN\n", 1, 42); 
	printf("%0*dFIN\n", 1, 42);
	printf("%.1dFIN\n", 42);
	printf("%-.1dFIN\n", 42);
	printf("%-*.2dFIN\n", 2, 42);*/