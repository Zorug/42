/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:30:15 by cgross-s          #+#    #+#             */
/*   Updated: 2025/06/19 19:35:44 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(char *nbr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		res = res * 10;
		res = res + (*nbr - '0');
		nbr++;
	}
	return (res * sign);
}

/*	Retorna o tempo atual em milissegundos*/
/*	gettimeofday() // tempo exato do sistema
	tv_sec: número de segundos desde a Epoch (1º de janeiro de 1970)
	tv_usec: microssegundos adicionais desde o último segundo (0 a 999999)*/
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
/*Por que não usar só tv_sec?
Porque ele só tem precisão de segundos. Para o projeto, isso seria impreciso:
    Você precisa saber se se passaram 500 ms, não só “1 segundo”
    tv_usec permite controlar ações em milissegundos*/

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+'))
			return (0);
		i++;
	}
	return (1);
}

/*Espera por um número de milissec, com mais precisão do que usleep direto.*/
/* int usleep(useconds_t microseconds);
🚧 Problemas com usleep:
1. ❌ Imprecisão em tempos grandes:
    Pode acabar dormindo mais tempo do que o pedido, especialmente se outros 
	processos interromperem a execução.
2. 🚫 Sem verificação durante o sono:
    Se o filósofo morrer durante o usleep, ele não perceberá.
    Durante o sono, nenhum código é executado.*/
/*Se usasse usleep, o filósofo poderia “comer por mais tempo que o necessário”, 
ou “não notar que outro morreu”.*/
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
/*✅ Para que serve no projeto:
Ajuda a controlar pausas com precisão, como:
    Tempo de comer (usleep(time_to_eat))
    Tempo de dormir
    Esperas suaves sem bloquear o monitor*/
