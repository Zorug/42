/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:02:04 by cgross-s          #+#    #+#             */
/*   Updated: 2025/05/21 21:51:53 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*O que faz:

    Verifica se a flag de morte (death) foi ativada
    Usa mutex para acesso seguro à variável compartilhada
Importância:
    Todas as ações dos filósofos verificam isso antes de prosseguir
    Garante que a simulação pare imediatamente após uma morte*/

int	death_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->data->death == 1)
		return (pthread_mutex_unlock(&philo->data->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
/*Lógica:
    Ignora se não há limite de refeições (nbr_of_meals == -1)
    Conta quantos filósofos comeram o suficiente
    Se todos comeram:
        Ativa flag de morte
        Imprime mensagem colorida de conclusão
Proteção:
    Usa meal_lock para acessar meals_eaten de forma segura
    Bloqueia dead_lock para modificar a flag de morte*/

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

/*Critério de Morte:
    Tempo desde a última refeição > time_to_die
    Só considera se não estiver comendo no momento
Proteção:
    Bloqueia meal_lock para acessar last_meal e is_eating*/

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

int	check_death(t_philo *philo)
/*    Verifica cada filósofo com is_dead()
    Se algum morreu:
        Imprime mensagem de morte
        Ativa flag global de morte
        Retorna 1 para encerrar a simulação*/
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nbr)
	{
		if (is_dead(&philo[i]))
		{
			print_messege(RED DIE COLOR_RESET, &philo[i]);
			pthread_mutex_lock(philo[i].dead_lock);
			philo[i].data->death = 1;
			pthread_mutex_unlock(philo[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}