/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:29:39 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/11 13:39:36 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	if (argc == 5)
		info->num_times_must_eat = -1;
	else
		info->num_times_must_eat = ft_atoi(argv[5]);
	data->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->death = 0;*/

void	init_data(char *str, t_data *data)
{
	data->num_philo = ft_atoi(str);
	data->threads = malloc(sizeof(pthread_t));
}

void	init_info(int argc, char **argv, t_info *info)
{
	if (argc == 5)
		info->num_times_must_eat = -1;
	else
		info->num_times_must_eat = ft_atoi(argv[5]);
	info->can_print = 0;
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->death = 0;
	info->num_philo_eaten = 1;
	info->num_eaten = 0;
	info->time_start = get_curr_time();
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
	while (i < data->num_philo)
	{
		printf("nosexq %d es pos: %d\n", i, data->philos[i].pos);
		if (pthread_create(&data->threads[i], NULL, &live, &data->philos[i]))
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
		data->philos[i].r_fork = 1;
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

int	init_mutex_info(t_info *info)
{
	int	i;
	int	error;

	i = 0;
	error = pthread_mutex_init(&info->death_mutex, NULL);
	if (error)
		return (0);
	error = pthread_mutex_init(&info->print, NULL);
	if (error)
		return (0);
	error = pthread_mutex_init(&info->num_eat, NULL);
	if (error)
		return (0);
	return (1);
}

int	init_philos(t_data *data, t_info *info)
{
	int		i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!init_mutex_info(info))
		return (0);
	while (i < data->num_philo)
	{
		data->philos[i].pos = i;
		data->philos[i].num_times_eat = 0;
		data->philos[i].info = info;
		i++;
	}
	init_mutex_philos(data);
	return (1);
}

