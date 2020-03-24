/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/24 11:56:26 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_putchar(char c, t_list *f)
{
	write(1, &c, 1);
	f->cont++;
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
			ft_store_data_def(&f);
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
}*/
long int	trans_neg(long int i)
{
	if (i < 0)
		i = 4294967295 + i + 1;
	return (i);
}

int		main(void)
{
	char c;

	c = 'a';
	printf("%05%", 'o');
	//printf("%x", -1);
	//print_spozero(22, 6, 6);
	//ft_printf("f",);

}

//si un unsigned int es negativo resta el mayor unsigned int 4,294,967,295+1 -(el numero que has puesto)
//ej = %u, -1 ==== 4,294,967,295