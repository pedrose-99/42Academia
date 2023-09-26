/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:00:09 by pserrano          #+#    #+#             */
/*   Updated: 2023/09/26 14:11:33 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eaten(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_mutex);
	pthread_mutex_lock(philo->print);
	if (philo->num_times_eat == philo->info->num_times_must_eat)
	{
		philo->info->num_philo_eaten++;
		philo->num_times_eat++;
	}
	if (philo->info->num_philo_eaten == philo->info->num_philo)
	{
		philo->info->can_print = 0;
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(philo->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_mutex);
	pthread_mutex_unlock(philo->print);
	return (0);
}
