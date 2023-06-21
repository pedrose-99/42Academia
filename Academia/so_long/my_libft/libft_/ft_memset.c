/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:29:19 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/09 12:45:06 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	d;
	char	*bcopy;

	bcopy = b;
	d = 0;
	while (d < len)
	{
		bcopy[d] = (unsigned char)c;
		d++;
	}
	return (b);
}
