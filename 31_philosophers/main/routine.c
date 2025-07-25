/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:04:24 by cgross-s          #+#    #+#             */
/*   Updated: 2025/06/15 19:37:12 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
/*	Pegar os garfos com mutex
	Atualizar estado
	Esperar tempo comendo
	Finalizar refeição 
	
	
	----- Qual o motivo de ter meal lock duas vezes???? ---
	*/
{
	if (philo->id % 2)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	print_message(LIGHTBLUE FORK COLOR_RESET, philo);
	if (philo->id % 2)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	print_message(LIGHTBLUE FORK COLOR_RESET, philo);
	print_message(LIGHTGREEN EAT COLOR_RESET, philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->is_eating = 1;
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

/* Sono do filósofo após comer */
void	dream(t_philo *philo)
{
	print_message(PURPLE SLEEP COLOR_RESET, philo);
	ft_usleep(philo->data->time_to_sleep);
}

/* O filósofo pensa antes de tentar comer novamente */
void	think(t_philo *philo)
{
	size_t	t_think;

	t_think = (philo->data->time_to_eat * 2) - philo->data->time_to_sleep;
	print_message(PINK THINK COLOR_RESET, philo);
	if (philo->data->philo_nbr % 2 != 0)
		ft_usleep(t_think * 0.42);
}

void	*routine(void *pointer)
/* principal da thread de cada filósofo */
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0 && philo->data->philo_nbr % 2 == 0)
		ft_usleep(1);
	else if (philo->id % 2 != 0 && philo->data->philo_nbr % 2 != 0)
		think(philo);
	while (!death_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}
