/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:33:17 by pserrano          #+#    #+#             */
/*   Updated: 2023/10/03 11:36:18 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_leaks()
{
	system("leaks -q philo");
}

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death_mutex);
	if (get_curr_time() - philo->time_finish_eat >= philo->info->time_die)
	{
		print_current_time(*philo, DEATH);
		philo->info->death = 1;
		pthread_mutex_unlock(philo->death_mutex);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
		return (1);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (0);
}

int	monitoring(t_data data)
{
	int	i;

	i = 0;
	while (i < data.num_philo)
	{
		if (is_philo_dead(&data.philos[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;
	int		i;

	atexit(ft_leaks);
	if (!check_args(argv, argc))
		return (0);
	init_data(argv[1], &data);
	data.threads = malloc(sizeof(pthread_t) * data.num_philo);
	init_info(argc, argv, &info);
	if (!init_philos(&data, &info))
		return (0);
	while (1)
	{
		if (monitoring(data) == 0)
			break ;
		usleep(500);
	}
	i = 0;
	while (i < data.num_philo)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	free_philo(&data);
	return (0);
}
