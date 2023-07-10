/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:17:16 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/10 11:52:45 by pserrano         ###   ########.fr       */
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
# include <sys/time.h>

# define SLEEP 1
# define THINK 2
# define EAT 3
# define DEATH 4
# define FORK 5

typedef struct s_info
{
	long				time_start;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					num_times_must_eat;
	int					death;
}			t_info;

typedef struct s_philo
{
	int				pos;
	int				time_finish_eat;
	int				action;
	int				num_times_eat;
	t_info			info;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}				t_philo;

typedef struct s_data
{
	long		time_start;
	int			curr_time;
	int			num_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			num_times_must_eat;
	pthread_t	*threads;
	t_philo		*philos;
}				t_data;

//init_struct.c
t_data			init_data(char **argv, int argc);
int				check_args(char **num_param, int argc);
int				init_philos_threads(t_data *data);
int				init_mutex_philos(t_data *data);
void			init_philos(t_data *data);

//philo.c
void			*live(void *philo);
void			eat(t_philo *philo);
void			action_time(int time_sleep, t_philo *philo);
int				is_dead(t_philo *philo);

//print_actions.c
void			print_current_time(t_philo philo, int action);
long			get_curr_time(void);

//philo_utils.c
int				check_num(char *num);
int				ft_atoi(const char *str);
void			free_philo(t_data *data);

#endif
