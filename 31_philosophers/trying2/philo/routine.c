/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:56:27 by cgross-s          #+#    #+#             */
/*   Updated: 2025/05/23 21:07:29 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Pontos-chave:
    Estratégia anti-deadlock: filósofos ímpares e pares pegam garfos em ordem diferente
    Atualização segura do estado com mutexes
    Tempo preciso de refeição usando ft_usleep()*/

void	eat(t_philo *philo)
{
    // Alterna a ordem de pegar os garfos baseado no ID (evita deadlock)
	if (philo->id % 2)
		pthread_mutex_lock(philo->r_fork);// Filósofo ímpar pega garfo direito primeiro
	else
		pthread_mutex_lock(philo->l_fork);// Filósofo par pega garfo esquerdo primeiro
	// Pega o segundo garfo
	if (philo->id % 2)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	print_message(LIGHTBLUE FORK COLOR_RESET, philo);
	print_message(LIGHTGREEN EAT COLOR_RESET, philo);

	// Atualiza estado de alimentação
	pthread_mutex_lock(philo->meal_lock);
	philo->is_eating = 1;
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);

	// Tempo gasto comendo
	ft_usleep(philo->data->time_to_eat);

	// Libera os garfos
	pthread_mutex_lock(philo->meal_lock);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
/*Simplicidade:
    Apenas imprime a mensagem e dorme pelo tempo especificado
    Usa ft_usleep() para precisão temporal*/
void	dream(t_philo *philo)
{
	print_message(PURPLE SLEEP COLOR_RESET, philo);
	ft_usleep(philo->data->time_to_sleep);
}
/*Otimização:
    Cálculo inteligente do tempo de pensar baseado nos outros tempos
    Fator 0.42 é um valor empírico para melhorar a sincronização*/
void	think(t_philo *philo)
{
	size_t	t_think;

	t_think = (philo->data->time_to_eat * 2) - philo->data->time_to_sleep;
	print_message(PINK THINK COLOR_RESET, philo);

	// Ajuste fino para número ímpar de filósofos
	if (philo->data->philo_nbr % 2 != 0)
		ft_usleep(t_think * 0.42);
}

/* Sincronização Inicial:
    Filósofos pares começam com pequeno atraso
    Filósofos ímpares em grupos ímpares começam pensando
Ciclo de Vida:
    Comer (com verificação de garfos)
    Dormir
    Pensar
    Repete até a morte */

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;

	// Atraso inicial para dessincronizar filósofos
	if (philo->id % 2 == 0 && philo->data->philo_nbr % 2 == 0)
		ft_usleep(1);
	else if (philo->id % 2 != 0 && philo->data->philo_nbr % 2 != 0)
		think(philo);

	// Loop principal de vida do filósofo
	while (!death_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}