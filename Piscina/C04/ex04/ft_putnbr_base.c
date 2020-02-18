/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:12:58 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/20 10:13:44 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_size(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	int		result;
	char	c;

	size = get_size(base);
	if (nbr >= size)
	{
		result = nbr / size;
		ft_putnbr_base(result, base);
		c = base[nbr % size];
		write(1, &c, 1);
	}
	else
	{
		c = base[nbr];
		write(1, &c, 1);
	}
}
