/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:23:53 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/10 10:09:11 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	const unsigned char		*srccopy;
	unsigned char			*dstcopy;

	srccopy = (const unsigned char*)src;
	dstcopy = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dstcopy[i] = srccopy[i];
		if (srccopy[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
