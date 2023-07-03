/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:17:16 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/03 11:52:43 by pserrano         ###   ########.fr       */
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
# include <semaphore.h>
# include <unistd.h>

# define SLEEP 1
# define THINK 2
# define EAT 3
# define DEATH 4

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_philo
{
	int		time_start;
	t_bool	death;
	int		action;
	int		num_times_eat;
}				t_philo;

typedef struct s_data
{
	int		num_philo;
	int		curr_time;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_times_must_eat;

}				t_data;

//init_struct.c
t_data			init_data(int num_philo, int time_die, int time_eat,
					int time_sleep);
t_data			init_num_must_eat(char *num_must_eat, t_data philo);
int				check_args(char **num_param, int argc);

//philo.c
int				check_first_args(char *num_philo, char *time_die,
					char *time_eat, char *sleep);

//philo_utils.c
int				check_num(char *num);
int				ft_atoi(const char *str);

#endif
