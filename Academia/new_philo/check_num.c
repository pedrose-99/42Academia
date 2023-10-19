/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:00:09 by pserrano          #+#    #+#             */
/*   Updated: 2023/10/14 10:14:07 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_eaten(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_mutex);
	if (philo->num_times_eat == philo->info->num_times_must_eat)
	{
		philo->info->num_philo_eaten++;
		philo->num_times_eat++;
	}
	pthread_mutex_unlock(philo->eat_mutex);
}
