/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:44:09 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/20 09:55:22 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char str)
{
	return (str == '\t' || str == '\v' || str == '\f' || str == '\r' ||
			str == '\n' || str == ' ') ? (1) : (0);
}

int	ft_simb(char str)
{
	return (str == '+' || str == '-') ? (1) : (0);
}

int	ft_num(char str)
{
	return (str >= '0' && str <= '9') ? (1) : (0);
}

int	ft_atoi(char *str)
{
	int i;
	int nb;
	int j;

	j = 0;
	i = 0;
	nb = 1;
	while (ft_isspace(str[i]))
		i++;
	while (ft_simb(str[i]))
	{
		if (str[i] == '-')
			nb = -nb;
		i++;
	}
	while (ft_num(str[i]))
	{
		j = j + ((int)str[i] - 48);
		i++;
		if (ft_num(str[i]))
			j = 10 * j;
	}
	j = j * nb;
	return (j);
}
