/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:05:54 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/09 13:10:08 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*srccopy;
	char	*dstcopy;

	srccopy = (char*)src;
	dstcopy = (char*)dst;
	if (srccopy == 0 && dstcopy == 0)
		return (0);
	while (n > 0)
	{
		*(dstcopy++) = *(srccopy++);
		n--;
	}
	return (dst);
}
