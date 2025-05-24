/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:23:55 by cgross-s          #+#    #+#             */
/*   Updated: 2025/05/23 19:34:24 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*O que faz:
    Libera a memória alocada para o array de garfos (mutexes)
    Libera a memória alocada para o array de filósofos
Importância:
    Evita vazamentos de memória (memory leaks)
    Limpa os dois principais arrays alocados dinamicamente*/
void	ft_free(t_data *data)
{
	free(data->forks);
	free(data->philos);
}

/*O que faz:
    Destrói os mutexes principais:
        dead_lock: protege a flag de morte
        meal_lock: protege o contador de refeições
        write_lock: protege a saída de mensagens
    Destrói todos os mutexes dos garfos (um por filósofo)
Por que é importante:
    Mutexes são recursos do sistema que precisam ser liberados
    Previne vazamentos de recursos (resource leaks)
    Boa prática de programação para evitar problemas em execuções repetidas*/

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