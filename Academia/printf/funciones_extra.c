/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:04:18 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/05 16:27:15 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
	return (size);
}

int		ft_count_nb(int nb)
{
	int				count;
	unsigned int	c;

	c = 0;
	count = 0;
	if (nb < 0)
	{
		c = nb * -1;
		count++;
	}
	if (nb > 0)
		c = nb;
	while (c >= 10)
	{
		c = c / 10;
		count++;
	}
	if (c < 10)
		count++;
	return (count);
}

void	ft_putnum(char *s, int n, int l)
{
	unsigned int c;

	c = 0;
	s[l--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		c = n * -1;
	}
	if (n > 0)
		c = n;
	while (c > 10 || (c <= 10 && c != 0))
	{
		s[l--] = c % 10 + 48;
		c = c / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*new;
	int		l;

	if (n < -2147483648)
		return (NULL);
	l = ft_count_nb(n);
	new = (char*)malloc(sizeof(char) * l + 1);
	if (new == 0)
		return (NULL);
	ft_putnum(new, n, l);
	return (new);
}


static int	ft_is_space(char str)
{
	return (str == '\t' || str == '\v' || str == '\f' || str == '\r' ||
			str == '\n' || str == ' ') ? (1) : (0);
}

static int	ft_is_num(char str)
{
	return (str >= '0' && str <= '9') ? (1) : (0);
}

int			ft_atoi(const char *str)
{
	long int i;
	long int nb;
	long int j;

	j = 0;
	i = 0;
	nb = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		nb = -nb;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_is_num(str[i]))
	{
		j = j + ((int)str[i] - 48);
		i++;
		if (ft_is_num(str[i]))
			j = 10 * j;
	}
	j = j * nb;
	return (j);
}
