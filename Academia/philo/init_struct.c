/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:29:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/09 20:38:45 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	init_data(char **argv, int argc)
{
	t_data			data;

	data.num_philo = ft_atoi(argv[1]);
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		data.num_times_must_eat = -1;
	else
		data.num_times_must_eat = ft_atoi(argv[5]);
	data.time_start = get_curr_time();
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

int		init_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (!(i % 2))
		{
		if (pthread_create(&data->threads[i], NULL, &live, &data->philos[i]))
			return (0);
		i++;
		}
	}
	usleep(300);
	i = 0;
	while (i < data->num_philo)
	{
		if ((i % 2))
		{
		if (pthread_create(&data->threads[i], NULL, &live, &data->philos[i]))
			return (0);
		i++;
		}
	}
	return (1);
}

int	init_mutex_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&(data->philos[i].right_fork), NULL);
		if (i == 0)
			data->philos[i].left_fork = &data->philos[data->num_philo - 1].right_fork;
		else
			data->philos[i].left_fork = &data->philos[i + 1].right_fork;
		i++;
	}
	if (init_philos_threads(data))
		return (1);
	return (0);
}

void	init_philos(t_data *data)
{
	int		i;

	i = 0;
	data->philos = malloc(sizeof(t_philo));
	while (i < data->num_philo)
	{
		data->philos[i].pos = i;
		data->philos[i].time_start_eat = -1;
		data->philos[i].time_finish_eat = -1;
		data->philos[i].time_star_sleep = -1;
		data->philos[i].time_finish_sleep = -1;
		data->philos[i].action = THINK;
		data->philos[i].num_times_eat = 0;
		data->philos[i].death = 0;
		i++;
	}
	init_mutex_philos(data);
}
