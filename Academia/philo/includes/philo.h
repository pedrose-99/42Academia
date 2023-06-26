/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:17:16 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/26 10:36:53 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

struct	s_philo
{
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_times_must_eat;
}		t_philo;

#endif