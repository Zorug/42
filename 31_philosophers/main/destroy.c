/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:36:07 by cgross-s          #+#    #+#             */
/*   Updated: 2025/06/19 19:36:48 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	free(data->forks);
	free(data->philos);
}

/* Destrói os mutexes que foram criados com pthread_mutex_init, 
para liberar os recursos do sistema associados a eles. */
void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->write_lock);
	while (i < data->philo_nbr)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}
