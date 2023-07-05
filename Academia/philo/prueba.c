/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:07:01 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/27 13:05:15 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/data.h"


int	check_first_args(char *num_data, char *time_die, char *time_eat,
			char *sleep)
{
	if (!check_num(num_data) || !check_num(time_die) || !check_num(time_eat)
		|| !check_num(sleep))
		return (0);
	return (1);jdjdjhjfhf
}

t_data	init_data(int num_data, int time_die, int time_eat, int time_sleep)
{
	t_data	data;

	data.num_data = num_data;
	data.time_die = time_die;
	data.time_eat = time_eat;
	data.time_sleep = time_sleep;
	data.num_times_must_eat = -1;
	return (data);
}

t_data	init_num_must_eat(char *num_must_eat, t_data data)
{
	data.num_times_must_eat = ft_atoi(num_must_eat);
	return (data);
}

int	check_args(char **num_param, int argc)
{
	if (argc == 5)
	{
		if (!check_num(num_param[1]) || !check_num(num_param[2])
			|| !check_num(num_param[3]) || !check_num(num_param[4]))
			return (0);
	}
	else
	{
		if (!check_num(num_param[1]) || !check_num(num_param[2])
			|| !check_num(num_param[3]) || !check_num(num_param[4])
			|| !check_num(num_param[5]))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc >= 5 && argc <= 6)
	{
		if (!check_args(argv, argc))
			printf("NO SE PUEDE\n");
		else
		{
			data = init_data(ft_atoi(argv[1]), ft_atoi(argv[2]),
					ft_atoi(argv[3]), ft_atoi(argv[4]));
			if (argc == 6)
				data = init_num_must_eat(argv[5], data);
			printf("num_data: %d, time_die: %d, time_eat: %d, time_Sleep: %d, must_eat: %d\n", data.num_data, data.time_die, data.time_eat, data.time_sleep, data.num_times_must_eat);
		}
	}
	else
		printf("ERROR: El número de argumentos no es valido.\n");
	return (0);
}

/*
#include "includes/data.h"


int	check_first_args(char *num_data, char *time_die, char *time_eat,
			char *sleep)
{
	if (!check_num(num_data) || !check_num(time_die) || !check_num(time_eat)
		|| !check_num(sleep))
		return (0);
	return (1);
}

t_data	init_data(int num_data, int time_die, int time_eat, int time_sleep)
{
	t_data	data;

	data.num_data = num_data;
	data.time_die = time_die;
	data.time_eat = time_eat;
	data.time_sleep = time_sleep;
	data.num_times_must_eat = -1;
	return (data);
}

t_data	init_num_must_eat(char *num_must_eat, t_data data)
{
	data.num_times_must_eat = ft_atoi(num_must_eat);
	return (data);
}

int check_args(char **num_param)
{
	
}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5)
	{
		if (!check_first_args(argv[1], argv[2], argv[3], argv[4]))
			printf("Los argumentos no son validos\n");
		else
			data = init_data(ft_atoi(argv[1]), ft_atoi(argv[2]),
					ft_atoi(argv[3]), ft_atoi(argv[4]));
	}
	else if (argc == 6)
	{
		if (!check_first_args(argv[1], argv[2], argv[3], argv[4])
			|| !check_num(argv[5]))
			printf("Los argumentos no son validos\n");
		else
		{
			data = init_data(ft_atoi(argv[1]), ft_atoi(argv[2]),
					ft_atoi(argv[3]), ft_atoi(argv[4]));
			data = init_num_must_eat(argv[5], data);
		}
	}
	else
		printf("ERROR: El número de argumentos no es valido.\n");
	return (0);
}

*/
