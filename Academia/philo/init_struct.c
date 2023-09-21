/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:29:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/09/21 11:15:37 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(char *str, t_data *data)
{
	data->num_philo = ft_atoi(str);
	//data->threads = malloc(sizeof(pthread_t *));
}

int	check_args(char **num_param, int argc)
{
	if (argc >= 5 && argc <= 6)
	{
		if (!check_num(num_param[1]) || !check_num(num_param[2])
			|| !check_num(num_param[3]) || !check_num(num_param[4]))
		{
			printf("ERROR: Los argumentos no son validos.\n");
			return (0);
		}
		if (argc == 6)
		{
			if (!check_num(num_param[5]))
			{
				printf("ERROR: Los argumentos no son validos.\n");
				return (0);
			}
		}
	}
	else
	{
		printf("ERROR: El número de argumentos no es valido.\n");
		return (0);
	}
	return (1);
}

int	init_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	//data->threads = malloc(sizeof(pthread_t) * data->num_philo);
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &live,
				&(data->philos[i])) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_mutex_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&(data->philos[i].right_fork), NULL);
		data->philos[i].r_fork = 0;
		if (i == 0)
		{
			data->philos[i].left_fork
				= &data->philos[data->num_philo - 1].right_fork;
			data->philos[i].l_fork
				= &data->philos[data->num_philo - 1].r_fork;
		}
		else
		{
			data->philos[i].left_fork = &data->philos[i - 1].right_fork;
			data->philos[i].l_fork = &data->philos[i - 1].r_fork;
		}
		i++;
	}
	if (init_philos_threads(data))
		return (1);
	return (0);
}

int	init_philos(t_data *data, t_info *info)
{
	int		i;

	i = 0;
	data->philos = (t_philo *) malloc(sizeof(t_philo) * (data->num_philo));
	if (!init_mutex_info(data))
	{
		free(data->philos);
		return (0);
	}
	while (i < data->num_philo)
	{
		data->philos[i].pos = i;
		data->philos[i].num_times_eat = 0;
		data->philos[i].info = info;
		data->philos[i].death_mutex = &(data->death_mutex);
		data->philos[i].print = &(data->print);
		data->philos[i].num_eat = &(data->num_eat);
		i++;
	}
	init_mutex_philos(data);
	return (1);
}

