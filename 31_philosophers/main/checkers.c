/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:23:59 by cgross-s          #+#    #+#             */
/*   Updated: 2025/06/19 19:29:43 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Verifica se algum filósofo já morreu, acessando a flag 
data->death com proteção de mutex. 
death == 1 já houve morte */
int	death_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->data->death == 1)
		return (pthread_mutex_unlock(&philo->data->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

/* Verifica se todos os filósofos comeram o número mínimo de vezes 
(nbr_of_meals) 
nbr_of_meals == -1 não há limite
death = 1 para parar a simulação*/
int	check_meals(t_philo *philos)
{
	int	i;
	int	philos_full;

	i = 0;
	philos_full = 0;
	if (philos->data->nbr_of_meals == -1)
		return (0);
	while (i < philos->data->philo_nbr)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos->data->nbr_of_meals)
			philos_full++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (philos_full == philos->data->philo_nbr)
	{
		pthread_mutex_lock(&philos->data->dead_lock);
		philos->data->death = 1;
		pthread_mutex_unlock(&philos->data->dead_lock);
		printf(ORANGE FULL COLOR_RESET);
		return (1);
	}
	return (0);
}

/* Verifica se o filósofo ficou tempo demais sem comer (morreu de fome). */
int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (((get_time() - philo->last_meal) > philo->data->time_to_die)
		&& !philo->is_eating)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

/*Percorre todos os filósofos e usa is_dead() para checar se algum morreu.*/
int	check_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nbr)
	{
		if (is_dead(&philo[i]))
		{
			print_message(RED DIE COLOR_RESET, &philo[i]);
			pthread_mutex_lock(philo[i].dead_lock);
			philo[i].data->death = 1;
			pthread_mutex_unlock(philo[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}
