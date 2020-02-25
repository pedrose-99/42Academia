/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:57:16 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/10 10:30:55 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scopy;

	scopy = (unsigned char*)s;
	while (n > 0)
	{
		if (*scopy == (unsigned char)c)
			return (scopy);
		scopy++;
		n--;
	}
	return (NULL);
}
