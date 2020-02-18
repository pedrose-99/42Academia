/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:29:25 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/16 19:41:02 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned	int lon;

	lon = 0;
	while (lon < n && src[lon] != '\0')
	{
		dest[lon] = src[lon];
		lon++;
	}
	while (lon < n)
	{
		dest[lon] = '\0';
		lon++;
	}
	return (dest);
}
