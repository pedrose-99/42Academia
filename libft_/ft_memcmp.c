/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:36:38 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/10 10:35:27 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1copy;
	unsigned char	*s2copy;

	s1copy = (unsigned char*)s1;
	s2copy = (unsigned char*)s2;
	while (n > 0)
	{
		if (*s1copy != *s2copy)
			return (*s1copy - *s2copy);
		s1copy++;
		s2copy++;
		n--;
	}
	return (0);
}
