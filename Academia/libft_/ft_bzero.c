/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:30:52 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/06 12:55:10 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				c;
	unsigned	char	*scopy;

	scopy = (unsigned char *)s;
	c = 0;
	while (c < n)
	{
		scopy[c] = 0;
		c++;
	}
}
