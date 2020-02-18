/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:06:30 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/20 20:07:51 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int k;

	k = nb;
	if (k < 0)
	{
		k = -k;
		ft_putchar('-');
	}
	if (k >= 10)
	{
		ft_putnbr(k / 10);
		ft_putchar(k % 10 + '0');
	}
	else
		ft_putchar(k + '0');
}
