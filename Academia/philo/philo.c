/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/04 12:45:40 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
/*
void	ft_leaks()
{
	system("leaks -q philo");
}

void	free_data(t_data data)
{
	int	i;

	i = 0;
	while (i < data.num_philo)
	{
		free(data.philos[i]);
		i++;
	}
}
void	init_philos(t_data data)
{
	int		i;

	i = 0;
	data.philos = malloc(sizeof(t_philo));
	while (i < data.num_philo)
	{
		data.philos[i]->eaten_time = 0;
		data.philos[i]->action = THINK;
		data.philos[i]->num_times_eat = 0;
		data.philos[i]->death = 0;
		i++;
	}
	i = 0;
	while (i < data.num_philo)
	{
		printf("%d\n", data.philos[i]->action);
		i++;
	}
}*/

int	main(int argc, char **argv)
{
	t_data	data;

	atexit(ft_leaks);
	if (argc >= 5 && argc <= 6)
	{
		if (!check_args(argv, argc))
			printf("ERROR: Los argumentos no son validos.\n");
		else
		{
			data = init_data(ft_atoi(argv[1]), ft_atoi(argv[2]),
					ft_atoi(argv[3]), ft_atoi(argv[4]));
			if (argc == 6)
				data = init_num_must_eat(argv[5], data);
			init_philos(data);
			free_data(data);
		}
	}
	else
		printf("ERROR: El número de argumentos no es valido.\n");
	return (0);
}

//MIRAR VIDEOS DE HILOS MUTEX ETC

/*
Variables a crear en estructura:

estructura philo que va a pertenecer a cada filosofo el cual debe tener:

Tiempo inicial.
Tiempo actual.
Variable muerto?
Accion de si esta durmiendo pensando o comiendo
LA accion de coger tenedor?
Threads
mutex
Imprimir cualquier accion cuando la haces. no se puede quedar un tenedor sin coger al principio

*/