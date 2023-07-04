/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:29:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/04 11:15:10 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	init_data(int num_philo, int time_die, int time_eat, int time_sleep)
{
	t_data			data;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	data.num_philo = num_philo;
	data.time_die = time_die;
	data.time_eat = time_eat;
	data.time_sleep = time_sleep;
	data.num_times_must_eat = -1;
	data.time_start = start_time.tv_usec;
	return (data);
}

t_data	init_num_must_eat(char *num_must_eat, t_data data)
{
	data.num_times_must_eat = ft_atoi(num_must_eat);
	return (data);
}

int	check_args(char **num_param, int argc)
{
	if (argc == 5)
	{
		if (!check_num(num_param[1]) || !check_num(num_param[2])
			|| !check_num(num_param[3]) || !check_num(num_param[4]))
			return (0);
	}
	else
	{
		if (!check_num(num_param[1]) || !check_num(num_param[2])
			|| !check_num(num_param[3]) || !check_num(num_param[4])
			|| !check_num(num_param[5]))
			return (0);
	}
	return (1);
}
