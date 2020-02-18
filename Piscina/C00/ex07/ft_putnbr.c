/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:17:44 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/14 11:20:09 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int tam;
	int nb_copy;

	nb_copy = nb;
	tam = 1;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (nb_copy / 10)
	{
		tam = tam * 10;
		nb_copy = nb_copy / 10;
	}
	while (tam)
	{
		ft_putchar((char)(nb / tam + 48));
		nb = nb % tam;
		tam = tam / 10;
	}
}
