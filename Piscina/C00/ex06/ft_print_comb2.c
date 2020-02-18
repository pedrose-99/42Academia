/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:10:44 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/10 19:25:21 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_n(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 1;
	c = '0';
	while (y <= 98)
	{
		while (x <= 99)
		{
			ft_putchar_n(c + y / 10, c + y % 10, c + x / 10, c + x % 10);
			x++;
		}
		y++;
		x = y;
		x++;
	}
}
