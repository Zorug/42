#include "philo.h"

void	ft_free(t_data *data)
{
	free(data->forks); // desaloca os mutexes dos garfos
	free(data->philos); // desaloca o array de filósofos
}

/* Destrói os mutexes que foram criados com pthread_mutex_init, 
para liberar os recursos do sistema associados a eles. */
void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	//dead_lock: protege a flag death.
	pthread_mutex_destroy(&data->dead_lock);
	//meal_lock: sincroniza acesso às refeições.
	pthread_mutex_destroy(&data->meal_lock);
	//write_lock: impede que múltiplas mensagens se misturem ao imprimir.
	pthread_mutex_destroy(&data->write_lock);
	/* Destroi cada mutex presente no array forks[], que representa 
	um garfo entre os filósofos. */
	while (i < data->philo_nbr)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}