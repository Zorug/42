/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:27:42 by cgross-s          #+#    #+#             */
/*   Updated: 2025/05/18 21:00:07 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Funcionamento:
    Bloqueio do Mutex: Garante que apenas um filósofo imprime por vez
    Verificação de Morte: Checa se a simulação ainda está ativa
    Formato da Mensagem: [tempo] [id_filósofo] [ação]
    Desbloqueio: Libera o mutex após imprimir
Por que é importante?
    Evita que mensagens se misturem na saída
    Garante que não haja impressão após uma morte */
void	print_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (!death_loop(philo))
		printf("%zu %zu %s", get_time() - philo->data->start, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}
/* Lógica de Monitoramento:
    Loop infinito verifica continuamente:
        check_meals(): Se todos comeram o suficiente
        check_death(): Se algum filósofo morreu
    Quebra o loop se alguma condição for atendida
Características:
    Executa em thread separada
    Consome poucos recursos (verificações espaçadas) */
void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (check_meals(philo) || check_death(philo))
			break;
	}
	return (pointer);
}
/* Fluxo de Execução:
    Thread do Monitor:
        Criada primeiro para começar vigilância imediata
    Threads dos Filósofos:
        Uma para cada filósofo
        Executam a função routine (definida em routine.c)
    Sincronização:
        pthread_join espera todas threads completarem
        Garante limpeza adequada dos recursos
Tratamento de Erros:
    Se qualquer thread falhar:
        Chama ft_destroy() para liberar recursos
        Encerra a simulação */
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