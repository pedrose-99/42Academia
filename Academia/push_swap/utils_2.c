/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:50:26 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:05:44 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	repeated_num(const int size, const int *numbers)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (i + j < size)
		{
			if (numbers[i] == numbers[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_number(const char *str, int *nbr, int i, int sign)
{
	long int	number;

	number = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number == 0)
			number = str[i] - 48;
		else
			number = number * 10 + str[i] - 48;
		i++;
		if ((sign == 1 && number > INT_MAX)
			|| (sign == -1 && number * -1 < INT_MIN))
			return (0);
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (0);
	*nbr = number * sign;
	return (1);
}

int	get_stack(const int size, const char **argv, int *numbers)
{
	int		i;
	int		repeated;

	i = 0;
	while (i < size)
	{
		if (!check_number(argv[i], &(numbers[i]), 0, 1))
			return (0);
		i++;
	}
	repeated = repeated_num(size, numbers);
	return (repeated);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
