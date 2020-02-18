/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:50:54 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/16 12:12:51 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int lon;

	lon = 0;
	while (src[lon])
	{
		dest[lon] = src[lon];
		lon++;
	}
	dest[lon] = '\0';
	return (dest);
}
