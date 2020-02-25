/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/02/25 12:46:39 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* int		ft_typeflag(char c)
{
	if (c == 'd')

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
	
}*/

int		ft_printf(const char *cosa, ...)
{
	va_list ap;
	int i;
	int p;
	int n;

	n = 0;
	i = 0;
	va_start(ap, cosa);
	if (cosa[i] == '%')
	{
		i++;
		if (cosa[i] == 'd')
		{
			i++;
			p = va_arg(ap, int);
		}
	write(1, &p, 1);
	n++;
	}
	va_end(ap);
	return (n);

}

int		main(void)
{
	printf("hola a todos %-0qd hola'\n", 3);
	ft_printf("%d", 3);
}
