/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:08:41 by pserrano          #+#    #+#             */
/*   Updated: 2023/10/03 10:33:45 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_space(char str)
{
	if (str == '\t' || str == '\v' || str == '\f' || str == '\r'
		|| str == '\n' || str == ' ')
		return (1);
	return (0);
}

static int	ft_is_num(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int	check_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_is_num(num[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	nb;
	long int	j;

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

void	free_philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philos[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->eat_mutex);
	free(data->philos);
	free(data->threads);
}
