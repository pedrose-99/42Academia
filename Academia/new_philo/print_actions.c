/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:27:15 by pserrano          #+#    #+#             */
/*   Updated: 2023/10/10 08:45:47 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_write(t_philo *philo)
{
	int	can_print;

	can_print = 1;
	printf("%ld ms philo %d is eating\n",
		get_curr_time() - philo->info->time_start, philo->pos + 1);
	pthread_mutex_lock(philo->eat_mutex);
	if (philo->info->num_philo_eaten == philo->info->num_philo)
	{
		pthread_mutex_lock(philo->death_mutex);
		can_print = 0;
		philo->info->death = 1;
		pthread_mutex_unlock(philo->death_mutex);
	}
	pthread_mutex_unlock(philo->eat_mutex);
	return (can_print);
}

void	print_current_time(t_philo philo, int action)
{
	pthread_mutex_lock(philo.print);
	if (philo.info->can_print)
	{
		if (action == SLEEP)
			printf("%ld ms philo %d is sleeping\n",
				get_curr_time() - philo.info->time_start, philo.pos + 1);
		else if (action == THINK)
			printf("%ld ms philo %d is thinking\n",
				get_curr_time() - philo.info->time_start, philo.pos + 1);
		else if (action == EAT)
			philo.info->can_print = check_write(&philo);
		else if (action == DEATH)
		{
			printf("%ld ms philo %d died\n",
				get_curr_time() - philo.info->time_start, philo.pos + 1);
			philo.info->can_print = 0;
		}
		else if (action == FORK)
			printf("%ld ms philo %d has taken a fork\n",
				get_curr_time() - philo.info->time_start, philo.pos + 1);
	}
	pthread_mutex_unlock(philo.print);
}

long	get_curr_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	action_time(int time_sleep, t_philo *philo)
{
	long	current_time;
	long	end_time;

	current_time = get_curr_time();
	end_time = current_time + time_sleep;
	while (get_curr_time() < end_time)
	{
		usleep(500);
		if (is_dead(philo) || check_eaten(philo))
		{
			pthread_mutex_unlock(&philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (0);
		}
	}
	return (1);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death_mutex);
	if (philo->info->death)
	{
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (0);
}
