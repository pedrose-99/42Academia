/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/09/21 14:48:44 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	action_time(int time_sleep, t_philo *philo)
{
	long	current_time;
	long	end_time;
	int		pos;

	current_time = get_curr_time();
	end_time = current_time + time_sleep;
	//printf("Tiempo que tiene que comer %ld la pos %d \n",  end_time, philo->pos + 1);
	while (get_curr_time() < end_time)
	{
		usleep(100);
		//printf("curr - slepp %lu \n",end_time - current_time);
		//current_time = get_curr_time();
	}
	//printf("Tiempo despues de comer %ld la pos %d \n", get_curr_time() - end_time, philo->pos + 1);
	//if (is_dead(philo))
	//	return (0);
	pos = philo->pos;
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
	if (get_curr_time() - philo->time_finish_eat >= philo->info->time_die)
	{
		print_current_time(*philo, DEATH);
		philo->info->death = 1;
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (0);
}

void	eatsegimpar(t_philo *philo, int fork_left, int fork_right)
{
	while (fork_left == 0 || fork_right == 0)
	{
		if (fork_left == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			if (*philo->l_fork == 0)
			{
				*philo->l_fork = 1;
				fork_left = 1;
				print_current_time(*philo, FORK);
			}
			pthread_mutex_unlock(philo->left_fork);
		}
		if (fork_right == 0)
		{
			pthread_mutex_lock(&philo->right_fork);
			if (philo->r_fork == 0)
			{
				philo->r_fork = 1;
				fork_right = 1;
				print_current_time(*philo, FORK);
			}
			pthread_mutex_unlock(&philo->right_fork);
		}
		if (is_dead(philo))
			return ;
		usleep(50);
	}
}

void	eatsegpar(t_philo *philo, int fork_left, int fork_right)
{
	while (fork_left == 0 || fork_right == 0)
	{
		if (fork_right == 0)
		{
			pthread_mutex_lock(&philo->right_fork);
			if (philo->r_fork == 0)
			{
				philo->r_fork = 1;
				fork_right = 1;
				print_current_time(*philo, FORK);
			}
			pthread_mutex_unlock(&philo->right_fork);
		}
		if (fork_left == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			if (*philo->l_fork == 0)
			{
				*philo->l_fork = 1;
				fork_left = 1;
				print_current_time(*philo, FORK);
			}
			pthread_mutex_unlock(philo->left_fork);
		}
		if (is_dead(philo))
			return ;
		usleep(50);
	}
}

int	eat(t_philo *philo)
{
	int	fork_left;
	int	fork_right;

	fork_left = 0;
	fork_right = 0;
	if (philo->pos % 2 == 0)
		eatsegimpar(philo, fork_left, fork_right);
	else
		eatsegpar(philo, fork_left, fork_right);
	print_current_time(*philo, EAT);
	philo->num_times_eat++;
	philo->time_finish_eat = get_curr_time();
	if (action_time(philo->info->time_eat, philo) == 0)
	{
		return (0);
	}
	//if (!check_eaten(philo))
	print_current_time(*philo, SLEEP);
	pthread_mutex_lock(&philo->right_fork);
	philo->r_fork = 0;
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	*philo->l_fork = 0;
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}


//PAsar otra rutina anterior.
void	*live(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->pos % 2 == 0)
		usleep(500);
	philo->time_finish_eat = get_curr_time();
	while (1)
	{
		if (is_dead(philo))
			return (NULL);
		if (eat(philo) == 0)
			return (NULL);
		if (action_time(philo->info->time_sleep, philo) == 0)
			return (NULL);
	//	if (check_num_eat(philo))
	//		return (NULL);
		print_current_time(*philo, THINK);
	}
	return (NULL);
}
