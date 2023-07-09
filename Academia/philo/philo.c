/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/09 20:37:46 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep(int time_sleep)
{
	long	current_time;
	long	end_time;

	current_time = get_curr_time();
	end_time = current_time + time_sleep;
	while (current_time < end_time)
	{
		//comprobar si se ha muerto alguno
		if (end_time - current_time > 10)
			usleep(10000);
		else
			usleep((end_time - current_time) * 1000);
	}
}

void	eat(t_philo *philo)
{
	//comprobar si se han muerto con variable nueva.
	phtread_mutex_lock(&philo->right_fork);
	printf("he cogido un tenedor");
	//comprobar si se han muerto con variable nueva.
	pthread_mutex_lock(philo->left_fork);
	printf("he cogido un tenedor");
	printf("El philosofo x esta comiendo\n");
	sleep(philo->time_eat); //mientras comes ñamñam
	printf("El philosofo x esta durmiendo\n");
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*live(void *phil)
{
	t_philo	*philo;
	
	philo = (t_philo *)phil;
	philo->time_finish_eat = get_curr_time();
	while (1)
	{
		eat(philo);
		sleep(philo->time_sleep);
		//comprobar si alguien ha muerto
		//si no esta muerto printear pensando
		printf("Estoy pensando");
	}
}