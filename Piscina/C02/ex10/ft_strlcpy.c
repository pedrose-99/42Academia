/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:03:15 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/17 11:39:26 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
		j++;
	}
	return (i - 1);
}
