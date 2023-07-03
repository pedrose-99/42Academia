/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:16:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/27 13:34:30 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
/*
void	ft_leaks()
{
	system("leaks -q philo");
}*/


int	main(int argc, char **argv)
{
	t_data	data;

	//atexit(ft_leaks);
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