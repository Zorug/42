#include "philo.h"

void	print_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (!death_loop(philo))
		printf("%zu %zu %s", get_time() - philo->data->start, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (check_meals(philo) || check_death(philo))
			break ;
	}
	return (pointer);
}

int	create_threads(t_data *data, t_philo *philos)
{
	pthread_t	checker;
	int			i;

	i = 0;
	if (pthread_create(&checker, NULL, &monitor, philos))
		ft_destroy(data);
	while (i < data->philo_nbr)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			ft_destroy(data);
		i++;
	}
	i = 0;
	if (pthread_join(checker, NULL))
		ft_destroy(data);
	while (i < data->philo_nbr)
	{
		if (pthread_join(philos[i].thread, NULL))
			ft_destroy(data);
		i++;
	}
	return (0);
}