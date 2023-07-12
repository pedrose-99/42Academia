/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:33:17 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/12 17:29:45 by pserrano         ###   ########.fr       */
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

	atexit(ft_leaks);
	if (!check_args(argv, argc))
		return (0);
	init_data(argv[1], &data);
	init_info(argc, argv, &info);
	if (!init_philos(&data, &info))
		return (0);
	i = 0;
	while (i < data.num_philo)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	printf("loqsea\n");
	printf("data %d\n", data.philos[0].pos);
	printf("PORQUe cojones %d\n", 2);
	//free_philo(&data, &info);
	return (0);
}
