/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:40:06 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/09 11:27:04 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char c;

	if (n >= 0)
	{
		c = 'P';
		write(1, &c, 1);
	}
	else if (n < 0)
	{
		c = 'N';
		write(1, &c, 1);
	}
}
