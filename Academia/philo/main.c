/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:33:17 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/11 13:30:26 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_leaks()
{
	system("leaks -q philo");
}
//	atexit(ft_leaks);


int	main(int argc, char **argv)
{
	t_data	*data;
	t_info	*info;
	int		i;

	data = malloc(sizeof(t_data));
	info = malloc(sizeof(t_info));
	if (!check_args(argv, argc))
		return (0);
	init_data(argv[1], data);
	init_info(argc, argv, info);
	if (!init_philos(data, info))
		return (0);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
	free_philo(data);
	return (0);
}
