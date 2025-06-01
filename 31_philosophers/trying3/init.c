#include "philo.h"

void	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		philos[i].data = data;
		philos[i].death = &data->death;
		philos[i].is_eating = 0;
		philos[i].id = i + 1;
		philos[i].death = &data->death;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_time();
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].write_lock = &data->write_lock;
		philos[i].l_fork = &data->forks[i];
		if (i == (data->philo_nbr - 1))
			philos[i].r_fork = &data->forks[0];
		else
			philos[i].r_fork = &data->forks[i + 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, size_t nbr_philos)
{
	size_t	i;

	i = 0;
	while (i < nbr_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_data(t_data *data, t_philo *philos, char **argv, char argc)
{
	data->death = 0;
	data->philos = philos;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	if (argc == 6)
		data->nbr_of_meals = ft_atoi(argv[5]);
	else
		data->nbr_of_meals = -1;
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start = get_time();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	init_forks(data->forks, data->philo_nbr);
}
