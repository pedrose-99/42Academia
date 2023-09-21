/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:33:17 by pserrano          #+#    #+#             */
/*   Updated: 2023/09/21 14:47:11 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_leaks()
{
	system("leaks -q philo");
}
//	

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;
	int		i;

//	atexit(ft_leaks);
	if (!check_args(argv, argc))
		return (0);
	init_data(argv[1], &data);
	data.threads = malloc(sizeof(pthread_t) * data.num_philo);
	init_info(argc, argv, &info);
	if (!init_philos(&data, &info))
		return (0);
	i = 0;
	while (i < data.num_philo)
	{
		//pthread_join(data.philos[i].thread, NULL);
		pthread_join(data.threads[i], NULL);
		i++;
	}
	free_philo(&data);
	return (0);
}


/*
	while (1)
	{
		i = 0;
		while (i < data.num_philo)
		{
			if (is_dead(&data.philos[i]))
			{
				//Terminaar
				break ;
			}
			if (data.philos[i].info->death == 1)
				break;
			i++;
		}
	}
*/