/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_para_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:59:54 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/06 09:09:00 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_list *f)
{
	
}
void	ft_putchar(char c, t_list *f)
{
	write(1, &c, 1);
	f->cont++;
}

void	print_zero(int	tam, t_list *f)
{
	int i;

	i = 0;
	while (i < tam)
	{
		ft_putchar(' ', f);
		i++;
		f->cont++;
	}
}

void	print_space(int	tam, t_list *f)
{
	int i;

	i = 0;
	while (i < tam)
	{
		ft_putchar('0', f);
		i++;
		f->cont++;
	}
}

void	print_spozero(char *p, int tam_num, t_list *f) //num de espacios o zeros
{
	int		zeros;
	int		spaces;


	if (f->precision < tam_num)
		spaces = f->width - tam_num;
	else 
		spaces = f->width - f->precision;
	print_space(spaces, f);
	zeros = f->precision - tam_num;
	print_zero(zeros, f);
	print_cosita(p, f);
}

void	print_cosita(char *p, t_list *f)
{
	while (*p)
	{
		ft_putchar(*p, f);
		p++;
	}
	//free(p);
}

void	print_int(t_list *f)
{
	int		i;
	int		tam_num;
	char	*p;

	i = va_arg(f->ap, int);
	p = ft_itoa(i);
	tam_num = ft_strlen(p);
	if (f->zero && f->precision && (!(f->minus)))
		print_spozero(p, tam_num, f);
	else if (f->minus && f->precision || f->zero)
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
		print_space((f->width - f->precision), f);
	}
	else if (f->minus)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if (f->zero)
	{
		print_zero((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->precision)
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
	}
	else if (!(f->zero) && (!(f->minus)) && f->width)
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
}

void	print_string(t_list *f)
{

}

void	print_cosas(t_list *f)
{
	if (f->spec == 'c')
		print_char(f);
	else if (f->spec == 'd' || f->spec == 'i')
		print_int(f);
	else if (f->spec == 's')
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