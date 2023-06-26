/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/26 10:46:41 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

struct s_philo	*init_philo(int num_philo, int time_die, int time_eat, int time_sleep)
{
	struct s_philo	philo;

	philo.num_philo = num_philo;
	philo.time_die = time_die;
	philo.time_die = time_eat;
	philo.time_sleep = time_sleep;
	philo.num_times_must_eat = 1;
	return (&philo);
}


int	main(int argc, char **argv)
{
	struct s_philo = *philo;

	if (argc == 5)
	{
		philo = init_philo(argv[1], argv[2], argv[3], argv[4]);
		printf("NUM_philo = %d, time_die = %d, time_eat = %d, time_sleep = %d.\n", philo->num_philo, philo->time_die, philo->time_eat, philo->time_sleep);
	}
	else if (argc == 6)
	{
		printf("Empezar el programa con los 5 argumentos\n");
	}
	else
	{
		printf("ERROR: El número de argumentos no es valido.\n");
	}
	printf("ARGV = %s\n", argv[1]);
	return (0);
}