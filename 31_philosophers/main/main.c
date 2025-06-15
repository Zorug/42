/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:45:18 by cgross-s          #+#    #+#             */
/*   Updated: 2025/06/15 16:55:10 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Esse é um caso especial importante: o que acontece se só houver 1 filósofo?
Como um filósofo precisa de dois garfos para comer, e há apenas um garfo, 
ele nunca conseguirá comer — vai morrer após o tempo de time_to_die.*/
void	one_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message(LIGHTBLUE FORK COLOR_RESET, philo);
	ft_usleep(data->time_to_die);
	print_message(RED DIE COLOR_RESET, philo);
	pthread_mutex_unlock(philo->r_fork);
}
/*🧠 Por que isso existe?
Se você não tratar o caso de 1 filósofo separadamente, ele ficaria preso 
tentando pegar o segundo garfo para sempre, ou seu programa pode travar.*/

int	check_args(char **argv)
/*Valida os argumentos da linha de comando. Ele verifica:
	Se são números (is_number)
	Se estão dentro de um intervalo válido (ft_atoi(argv[i]) ≥ 0)
Retorna 1 (erro) se algum argumento for inválido.*/
{
	if (ft_atoi(argv[1]) <= 0 || !is_number(argv[1]))
		return (write(1, "Wrong number_of_philosophers\n", 30), 1);
	if (ft_atoi(argv[2]) < 0 || !is_number(argv[2]))
		return (write(1, "Wrong time_to_die.\n", 20), 1);
	if (ft_atoi(argv[3]) < 0 || !is_number(argv[3]))
		return (write(1, "Wrong time_to_eat.\n", 20), 1);
	if (ft_atoi(argv[4]) < 0 || !is_number(argv[4]))
		return (write(1, "Wrong time_to_sleep.\n", 22), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || !is_number(argv[5])))
		return (write(1, "Wrong number_of_times_must_eat.\n", 32), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
	{
		printf("Wrong number os arguments.\n");
		return (EXIT_FAILURE);
	}
	if (check_args(argv) != 0)
		return (EXIT_FAILURE);
	philos = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philos)
		return (EXIT_FAILURE);
	init_data(&data, philos, argv, argc);
	init_philos(&data, philos);
	if (data.philo_nbr == 1)
		one_philo(&data, &philos[0]);
	else
		create_threads(&data, philos);
	ft_destroy(&data);
	ft_free(&data);
	return (0);
}

/*
exemplo de uso
./philo 5 800 200 200 [opcional: n_vezes_para_comer]
*/