/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:33:17 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/10 15:52:15 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_leaks()
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

//	atexit(ft_leaks);
	if (argc >= 5 && argc <= 6)
	{
		if (!check_args(argv, argc))
		{
			printf("ERROR: Los argumentos no son validos.\n");
			return (0);
		}
		else
		{
			data = init_data(argv, argc);
			init_philos(&data);
		}
	}
	else  
		printf("ERROR: El número de argumentos no es valido.\n");
	i = 0;
	while (i < data.num_philo)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	free_philo(&data);
	return (0);
}
