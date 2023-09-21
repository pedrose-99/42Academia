/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:00:09 by pserrano          #+#    #+#             */
/*   Updated: 2023/09/21 10:40:39 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eaten(t_philo *philo)
{
	pthread_mutex_lock(philo->num_eat);
	if (philo->info->num_eaten == philo->info->num_philo)
	{
		pthread_mutex_unlock(philo->num_eat);
		return (1);
	}
	pthread_mutex_unlock(philo->num_eat);
	return (0);
}

int	check_num_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->num_eat);
	if (philo->num_times_eat == philo->info->num_times_must_eat)
	{
		philo->info->num_eaten++;
	}
	if (philo->info->num_eaten == philo->info->num_philo)
	{
		pthread_mutex_unlock(philo->num_eat);
		return (1);
	}
	pthread_mutex_unlock(philo->num_eat);
	return (0);
}
