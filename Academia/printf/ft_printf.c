/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/23 21:54:49 by pedro            ###   ########.fr       */
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
char	*type_p(char *def)
{
	int	p;
	
	p = 0;
	def[p] = '0';
	p++;
	def[p] = 'x';
	p++;
	return (def);
}

char	 *trans_hexp(long int i, char c)
{
	long int			i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 3;
	hex_char = "0123456789abcdef";
	i_copy = trans_neg(i);
	while (i_copy >= 16 && (i_copy /= 16))
		count++;
	i_copy = trans_neg(i);
	if (!(def = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	def[count] = '\0';
	while (i_copy > 15)
	{
		--count;
		def[count] = hex_char[i_copy % 16];
		i_copy /= 16;
	}
	def[--count] = hex_char[i_copy % 16];
	def = type_p(def);
	return (def);
}
int		main(void)
{
	char	*f;
	
	f = trans_hexp(429, 'x');
	printf("%p", 429);
	printf("%s", f);
	//printf("%x", -1);
	//print_spozero(22, 6, 6);
	//ft_printf("f",);

}

//si un unsigned int es negativo resta el mayor unsigned int 4,294,967,295+1 -(el numero que has puesto)
//ej = %u, -1 ==== 4,294,967,295