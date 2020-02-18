/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:53:34 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/17 12:14:01 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_alphanum(char str)
{
	return ((str >= 'A' && str <= 'Z') || (str >= '0' && str <= '9') ||
			(str >= 'a' && str <= 'z')) ? (1) : (0);
}

int		ft_is_low(char str)
{
	return (str >= 'a' && str <= 'z') ? (1) : (0);
}

int		ft_is_cap(char str)
{
	return (str >= 'A' && str <= 'Z') ? (1) : (0);
}

char	*ft_strcapitalize(char *str)
{
	int lon;

	lon = 0;
	if (ft_is_low(*str))
		*str = *str - 32;
	while (*str)
	{
		if (!ft_is_alphanum(*str) && ft_is_low(*(str + 1)))
		{
			*(str + 1) = *(str + 1) - 32;
		}
		if (ft_is_alphanum(*(str - 1)) && ft_is_cap(*str))
		{
			*str = *str + 32;
		}
		str++;
		lon++;
	}
	str = str - lon;
	return (str);
}
