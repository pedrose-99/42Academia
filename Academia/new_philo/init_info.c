/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:01:45 by pserrano          #+#    #+#             */
/*   Updated: 2023/09/26 11:00:50 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(int argc, char **argv, t_info *info)
{
	if (argc == 5)
		info->num_times_must_eat = -1;
	else
		info->num_times_must_eat = ft_atoi(argv[5]);
	info->can_print = 1;
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->death = 0;
	info->num_philo_eaten = 0;
	info->time_start = get_curr_time();
}

int	init_mutex_info(t_data *data)
{
	int	error;

	error = pthread_mutex_init(&(data->death_mutex), NULL);
	if (error)
		return (0);
	error = pthread_mutex_init(&(data->print), NULL);
	if (error)
		return (0);
	error = pthread_mutex_init(&(data->eat_mutex), NULL);
	if (error)
		return (0);
	return (1);
}
