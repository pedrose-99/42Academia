/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/12 18:32:30 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_time(int time_sleep, t_philo *philo)
{
	long	current_time;
	long	end_time;

	current_time = get_curr_time() - philo->info->time_start;
	end_time = current_time + time_sleep;
	while (current_time < end_time && !is_dead(philo))
	{
		if (end_time - current_time > 10)
			usleep(10000);
		else
			usleep((end_time - current_time) * 1000);
		current_time = get_curr_time() - philo->info->time_start;
	}
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death_mutex);
	if (philo->info->death)
	{
		pthread_mutex_unlock(&philo->info->death_mutex);
		return (1);
	}
	if (get_curr_time() - philo->time_finish_eat >= philo->info->time_die)
	{
		print_current_time(*philo, DEATH);
		philo->info->death = 1;
		pthread_mutex_unlock(&philo->info->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death_mutex);
	return (0);
}

void	eatseg(t_philo *philo, int fork_left, int fork_right)
{
	while (fork_left == 0 || fork_right == 0)
	{
		pthread_mutex_lock(&philo->right_fork);
		if (philo->r_fork == 0)
		{
			philo->r_fork = 1;
			fork_right = 1;
			print_current_time(*philo, FORK);
		}
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		if (*philo->l_fork == 0)
		{
			*philo->l_fork = 1;
			fork_left = 1;
			print_current_time(*philo, FORK);
		}
		pthread_mutex_unlock(philo->left_fork);
		if (is_dead(philo))
			return ;
	}
}

void	eat(t_philo *philo)
{
	int	fork_left;
	int	fork_right;

	fork_left = 0;
	fork_right = 0;
	eatseg(philo, fork_left, fork_right);
	if (is_dead(philo))
		return ;
	print_current_time(*philo, EAT);
	philo->num_times_eat++;
	philo->time_finish_eat = get_curr_time();
	action_time(philo->info->time_eat, philo);
	if (is_dead(philo))
		return ;
	if (!check_eaten(philo))
		print_current_time(*philo, SLEEP);
	pthread_mutex_lock(&philo->right_fork);
	philo->r_fork = 0;
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	*philo->l_fork = 0;
	pthread_mutex_unlock(philo->left_fork);
}


void	*live(void *phil)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)phil;
	printf("El philo es el %i\n", philo->pos);
	i = philo->pos;
	if (i % 2 == 0)
		usleep(500);
	printf("El JAJASSHSHD es el %i\n", philo->pos);
	philo->time_finish_eat = get_curr_time();
	while (1)
	{
		if (is_dead(philo))
			return (NULL);
		eat(philo);
		if (is_dead(philo))
			return (NULL);
		action_time(philo->info->time_sleep, philo);
		if (is_dead(philo))
			return (NULL);
		if (check_num_eat(philo))
		{
			return (NULL);
		}
		print_current_time(*philo, THINK);
	}
	return (NULL);
}
