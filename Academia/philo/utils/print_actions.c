/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:27:15 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/04 11:27:43 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_current_time(t_data data, int action)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	data.curr_time = current_time.tv_usec;
	if (action == 1)
		printf("%d ms is sleeping\n", data.curr_time - data.time_start);
	else if (action == 2)
		printf("%d ms is thinking\n", data.curr_time - data.time_start);
	else if (action == 3)
		printf("%d ms is eating\n", data.curr_time - data.time_start);
	else if (action == 4)
		printf("%d ms died\n", data.curr_time - data.time_start);
}