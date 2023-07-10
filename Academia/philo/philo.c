/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/10 13:45:00 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_time(int time_sleep, t_philo *philo)
{
	long	current_time;
	long	end_time;

	printf("COmiendo en tiempo: %d\n", time_sleep);
	current_time = get_curr_time();
	end_time = current_time + time_sleep;
	while (current_time < end_time && is_dead(philo))
	{
		if (end_time - current_time > 10)
			usleep(10000);
		else
			usleep((end_time - current_time) * 1000);
	}
}

int	is_dead(t_philo *philo)
{
	if (get_curr_time() - philo->time_finish_eat >= philo->info->time_die)
	{
		pthread_mutex_lock(philo->info->death_mutex);
		print_current_time(*philo, DEATH);
		philo->info->death = 1;
		pthread_mutex_unlock(philo->info->death_mutex);
		return (1);
	}
	if (philo->info->death)
		return (1);
	return (0);
}

void	eat(t_philo *philo)
{
	if (!is_dead(philo))
		pthread_mutex_lock(&philo->right_fork);
	print_current_time(*philo, FORK);
	if (!is_dead(philo))
		pthread_mutex_lock(philo->left_fork);
	print_current_time(*philo, FORK);
	print_current_time(*philo, EAT);
	action_time(philo->info->time_eat, philo);
	print_current_time(*philo, SLEEP);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->num_times_eat++;
}

void	*live(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	philo->time_finish_eat = get_curr_time();
	while (1)
	{
		eat(philo);
		action_time(philo->info->time_sleep, philo);
		if (philo->info->death)
			return (NULL);
		if (philo->num_times_eat == philo->info->num_times_must_eat)
			return (NULL);
		print_current_time(*philo, THINK);
	}
}
