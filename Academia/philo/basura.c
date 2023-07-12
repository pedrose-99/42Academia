#include "philo.h"

void	action_time(int time_sleep, t_philo *philo)
{
	long	current_time;
	long	end_time;

	current_time = get_curr_time() - philo->info->time_start;
	end_time = current_time + time_sleep;
	while (current_time < end_time && !is_dead(philo))
	{
		if (end_time - current_time > 10)
			usleep(10000);
		else
			usleep((end_time - current_time) * 1000);
		current_time = get_curr_time() - philo->info->time_start;
	}
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death_mutex);
	if (philo->info->death)
	{
		pthread_mutex_unlock(&philo->info->death_mutex);
		return (1);
	}
	if (get_curr_time() - philo->time_finish_eat >= philo->info->time_die)
	{
		print_current_time(*philo, DEATH);
		philo->info->death = 1;
		pthread_mutex_unlock(&philo->info->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death_mutex);
	return (0);
}

void	eat(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->right_fork);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}
	print_current_time(*philo, FORK);
	pthread_mutex_lock(philo->left_fork);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}
	sleep_action(philo);
}
/*	if (check_num_eat(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}*/
void	sleep_action(t_philo *philo)
{
	print_current_time(*philo, FORK);
	print_current_time(*philo, EAT);
	philo->num_times_eat++;
	philo->time_finish_eat = get_curr_time();
	action_time(philo->info->time_eat, philo);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}
	if (!check_eaten(philo))
		print_current_time(*philo, SLEEP);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*live(void *phil)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)phil;
	i = philo->pos;
	if (i % 2 == 0)
		usleep(500);
	philo->time_finish_eat = get_curr_time();
	while (1)
	{
		if (is_dead(philo))
			return (NULL);
		eat(philo);
		if (is_dead(philo))
			return (NULL);
		action_time(philo->info->time_sleep, philo);
		if (is_dead(philo))
			return (NULL);
		if (check_num_eat(philo))
			return (NULL);
		print_current_time(*philo, THINK);
	}
	return (NULL);
}









#include "philo.h"

void	ft_leaks()
{
	system("leaks -q philo");
}
//
void	guardar_endata(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].info = philo[i].info;
		data->philos[i].l_fork = philo[i].l_fork;
		data->philos[i].left_fork = philo[i].left_fork;
		data->philos[i].num_times_eat = philo[i].num_times_eat;
		data->philos[i].pos = philo[i].pos;
		data->philos[i].r_fork = philo[i].r_fork;
		data->philos[i].right_fork = philo[i].right_fork;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;
	t_philo	*philo;
	int		i;

	atexit(ft_leaks);
	if (!check_args(argv, argc))
		return (0);
	init_data(argv[1], &data);
	init_info(argc, argv, &info);
	philo = malloc(sizeof(t_philo *) * data.num_philo);
	printf("hagdggd\n");
	guardar_philos(&data, &info, philo);
	printf("hagdggd\n");
	//data.philos = philo;
	guardar_endata(&data, philo);
	init_philos_threads(&data);
	i = 0;
	while (i < data.num_philo)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	printf("loqsea\n");
	printf("data %d\n", data.philos[3].pos);
	printf("PORQUe cojones %d\n", 2);
	free_philo(&data, &info, philo);
	//free(philo);
	return (0);
}


void	guardar_philos(t_data *data, t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	if (!init_mutex_info(info))
		return ;
	while (i < data->num_philo)
	{
		philo[i].pos = i;
		philo[i].num_times_eat = 0;
		philo[i].info = info;
		i++;
	}
	init_mutex_philo(philo, data);
}
void	init_mutex_philo(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&(philos[i].right_fork), NULL);
		data->philos[i].r_fork = 0;
		if (i == 0)
		{
			philos[i].left_fork
				= &philos[data->num_philo - 1].right_fork;
			philos[i].l_fork
				= &philos[data->num_philo - 1].r_fork;
		}
		else
		{
			philos[i].left_fork = &philos[i - 1].right_fork;
			philos[i].l_fork = &philos[i - 1].r_fork;
		}
		i++;
	}
}


