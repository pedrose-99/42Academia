/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:28:48 by pserrano          #+#    #+#             */
/*   Updated: 2019/12/09 10:35:43 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last_pos;

	last_pos = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_pos = s;
		s++;
	}
	if (last_pos)
		return ((char*)last_pos);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
