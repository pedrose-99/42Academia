/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:27:15 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/10 10:54:32 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_current_time(t_philo philo, int action)
{
	if (action == SLEEP)
		printf("%ld ms philo %d is sleeping\n",
			get_curr_time() - philo.info->time_start, philo.pos + 1);
	else if (action == THINK)
		printf("%ld ms philo %d is thinking\n",
			get_curr_time() - philo.info->time_start, philo.pos + 1);
	else if (action == EAT)
		printf("%ld ms philo %d is eating\n",
			get_curr_time() - philo.info->time_start, philo.pos + 1);
	else if (action == DEATH)
		printf("%ld ms philo %d died\n",
			get_curr_time() - philo.info->time_start, philo.pos + 1);
	else if (action == FORK)
		printf("%ld philo %d has taken a fork\n",
			get_curr_time() - philo.info->time_start, philo.pos + 1);
}

long	get_curr_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
