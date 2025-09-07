/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:48:48 by cgross-s          #+#    #+#             */
/*   Updated: 2025/06/19 20:03:32 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Impressão de mensagens com sincronização */
void	print_message(char *str, t_philo *philo)
/*	pthread_mutex_lock(philo->write_lock);
	Bloqueia o mutex de escrita, impedindo outras threads de 
	imprimirem ao mesmo tempo.*/
/*	if (!death_loop(philo))
	Verifica se ninguém morreu ainda (evita imprimir após fim da simulação).*/
/*	get_time() - philo->data->start
	Mostra o tempo decorrido desde o início da simulação.*/
/*	Libera o mutex para a próxima thread poder imprimir. */
{
	pthread_mutex_lock(philo->write_lock);
	if (!death_loop(philo))
		printf("%zu %zu %s", get_time() - philo->data->start, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

/* Monitoramento da simulação */
void	*monitor(void *pointer)
/*	O que faz?
	Essa função é uma thread separada responsável por monitorar a simulação:
    	Detecta se todos os filósofos comeram o suficiente (check_meals)
    	Ou se algum morreu de fome (check_death)
	Se qualquer uma dessas condições for verdade, ela interrompe a simulação.
	Nota: A função monitor() roda em paralelo com os filósofos. 
		É o "vigilante" do sistema.*/
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

/* Criação e sincronização das threads */
int	create_threads(t_data *data, t_philo *philos)
/* Essa função é responsável por:
    Criar todas as threads dos filósofos
    Criar a thread de monitoramento (monitor)
    Aguardar (join) o fim das threads */
/*	pthread_create(&checker, NULL, &monitor, philos)
	Essa thread recebe o vetor philos como argumento.
	Fica em loop até detectar fim da simulação.*/
/* 	Cada filósofo roda sua routine() 
		(vida: pensar → pegar garfos → comer → dormir...)*/
/*pthread_join espera o monitor acabar*/
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
