/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:03:15 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/10 11:06:11 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char			*srcopy;
	size_t			j;

	j = 0;
	srcopy = (char*)src;
	if (size == 0)
		return (ft_strlen(srcopy));
	if (!dst || !src)
		return (0);
	while (j < size - 1 && srcopy[j])
	{
		dst[j] = srcopy[j];
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(srcopy));
}
