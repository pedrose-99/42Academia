/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:02:36 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/06 13:02:58 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	count;

	ds = 0;
	while (dst[ds] && ds < dstsize)
		ds++;
	count = 0;
	while ((count + ds + 1) < dstsize && src[count])
	{
		dst[count + ds] = src[count];
		count++;
	}
	if ((ds + count) < dstsize)
		dst[count + ds] = '\0';
	return (ds + ft_strlen(src));
}
