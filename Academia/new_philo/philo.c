/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/10/14 10:15:31 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eatimpar(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_dead(philo))
		return (0);
	print_current_time(*philo, FORK);
	pthread_mutex_lock(&philo->right_fork);
	if (is_dead(philo))
		return (0);
	print_current_time(*philo, FORK);
	philo->num_times_eat++;
	print_current_time(*philo, EAT);
	pthread_mutex_lock(&philo->mutex_time_eat);
	philo->time_finish_eat = get_curr_time();
	pthread_mutex_unlock(&philo->mutex_time_eat);
	if (action_time(philo->info->time_eat, philo) == 0)
		return (0);
	return (1);
}

int	eatpar(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	if (is_dead(philo))
		return (0);
	print_current_time(*philo, FORK);
	pthread_mutex_lock(philo->left_fork);
	if (is_dead(philo))
		return (0);
	print_current_time(*philo, FORK);
	philo->num_times_eat++;
	print_current_time(*philo, EAT);
	philo->time_finish_eat = get_curr_time();
	if (action_time(philo->info->time_eat, philo) == 0)
		return (0);
	return (1);
}

int	check_condition(t_philo *philo)
{
	if (philo->info->num_philo > 50)
	{
		if (philo->pos % 2 == 0)
		{
			if (eatimpar(philo) == 0)
				return (0);
		}
		else
		{
			if (eatpar(philo) == 0)
				return (0);
		}
	}
	else
		if (eatimpar(philo) == 0)
			return (0);
	return (1);
}

int	eat(t_philo *philo)
{
	if (check_condition(philo) == 0)
		return (0);
	print_current_time(*philo, SLEEP);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

void	*live(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->pos % 2 == 0)
		usleep(500);
	pthread_mutex_lock(&philo->mutex_time_eat);
	philo->time_finish_eat = get_curr_time();
	pthread_mutex_unlock(&philo->mutex_time_eat);
	while (1)
	{
		if (is_dead(philo))
			return (NULL);
		if (eat(philo) == 0)
			return (NULL);
		if (action_time(philo->info->time_sleep, philo) == 0)
			return (NULL);
		if (is_dead(philo))
			return (NULL);
		print_current_time(*philo, THINK);
	}
	return (NULL);
}
