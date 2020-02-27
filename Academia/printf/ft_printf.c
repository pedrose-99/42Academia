/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/02/27 12:05:25 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

 int		ft_typeflag(char c)
{
	if (cosa[i] == 'd')
	{
		i++;
		p = va_arg(ap, int);
	}
	if (c == 'c')

	if (c == 'e')

	if (c == 'f')

	if (c == 'g')

	if (c == 'i')

	if (c == 'o')

	if (c == 's')

	if (c == 'u')

	if (c == 'x')

	if (c == '%')

	if (c == '-')

	if (ft_isnum(c))
	
}


int		ft_case_first_num(va_list ap)
{
	va_list next;
	int		num; // hacer un tipo de variable que englobe a todos los numeros (esperar a Mi niño)
	int		tam;
	char	*numdef;


	va_copy(next, ap);
	if (cosa[f->pos++] == '0')
	{
		num = va_arg(next, int) //hacer un tipo de variable que englobe a todos los numeros (esperar a Mi niño)
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

 
int		ft_printf(const char *cosa, ...)
{
	va_list ap;
	t_list	*f;
	int		i;

	i = 0;
	//if(!(f = malloc(sizeof(t_list) *  )))
		return (-1);
	va_start(ap, cosa);
	while (cosa[i])
	{
		if (cosa[i] == '%')
		{
			ft_alm_datos(&cosa[i]);
			i = f->numdespec + i;
		}
		else
		{
			ft_putchar(cosa[i]);
			i++;
			f->cont++;
		}
	}
}*/
int		main(void)
{
	printf("hola %0-7d holabuenosdoas", 89);
	//ft_printf("%f",);
}
