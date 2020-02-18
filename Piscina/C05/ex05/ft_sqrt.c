/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 07:36:06 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/24 00:42:00 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt(int nb)
{
	int i;
	int result;

	i = 1;
	result = i * i;
	if (nb == 1)
		return (1);
	while (result != nb && i < 46341)
	{
		i++;
		result = i * i;
		if (result == nb)
			return (i);
	}
	return (0);
}
