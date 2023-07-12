/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:17:16 by pserrano          #+#    #+#             */
/*   Updated: 2023/07/12 16:52:21 by pserrano         ###   ########.fr       */
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
	int					num_times_must_eat;
	int					num_philo;
	long				time_start;
	long				time_die;
	long				time_eat;
	long				time_sleep;
	int					num_eaten;
	int					can_print;
	int					death;
	int					unlock_dead;
	int					num_philo_eaten;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		num_eat;
	pthread_mutex_t		print;
}			t_info;

typedef struct s_philo
{
	long			time_finish_eat;
	int				num_times_eat;
	int				*l_fork;
	int				pos;
	int				r_fork;
	t_info			*info;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
}				t_philo;

typedef struct s_data
{
	int			num_philo;
	pthread_t	*threads;
	t_philo		*philos;
}				t_data;

//init_struct.c
void			init_data(char *str, t_data *data);
int				check_args(char **num_param, int argc);
int				init_philos_threads(t_data *data);
int				init_mutex_philos(t_data *data);
int				init_philos(t_data *data, t_info *info);
void			guardar_philos(t_data *data, t_info *info, t_philo *philo);

//init_info.c
void			init_info(int argc, char **argv, t_info *info);
int				init_mutex_info(t_info *info);

//philo.c
void			*live(void *philo);
void			eat(t_philo *philo);
void			action_time(int time_sleep, t_philo *philo);
int				is_dead(t_philo *philo);
void			eatseg(t_philo *philo, int fork_left, int fork_right);


//check_num.c
int				check_eaten(t_philo *philo);
int				check_num_eat(t_philo *philo);


//print_actions.c
void			print_current_time(t_philo philo, int action);
long			get_curr_time(void);

//philo_utils.c
int				check_num(char *num);
int				ft_atoi(const char *str);
void			free_philo(t_data *data, t_info *info, t_philo *philos);

#endif
