/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:31:35 by cgross-s          #+#    #+#             */
/*   Updated: 2025/05/18 12:40:12 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Special case handler for when there's only 1 philosopher */
void	one_philo(t_data *data, t_philo *philo)
{
	// Locks the single fork (since there's only one)
	pthread_mutex_lock(philo->r_fork);
	// Prints that the philosopher took the fork
	print_message(LIGHTBLUE FORK COLOR_RESET, philo);
	// Waits until starvation time (time_to_die) elapses
	ft_usleep(data->time_to_die);
	// Prints death message
	print_message(RED DIE COLOR_RESET, philo);
	// Releases the fork (though this is technically unnecessary 
	// since the program ends)
	pthread_mutex_unlock(philo->r_fork);
}

/* Validates command line arguments */
int	check_args(char **argv)
/* Checks:
    Philosopher count must be positive
    Time values must be non-negative
    Optional meal count must be positive if provided
    All arguments must be numeric
Returns: 0 if valid, 1 with error message if invalid */
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

	// Argument count check
	if (argc != 5 && argc != 6)
	{
		printf("Wrong number os arguments.\n");
		return(EXIT_FAILURE);
	}

	// Argument validation
	if (check_args(argv) != 0)
		return (EXIT_FAILURE);

	// Memory allocation
	philos = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philos)
		return (EXIT_FAILURE);

	// Initialization
	init_data(&data, philos, argv, argc);
	init_philos(&data, philos);

	// Special case: 1 philosopher
	if (data.philo_nbr == 1)
		one_philo(&data, &philos[0]);
	else
		create_threads(&data, philos); // spawns all philosopher threads

	// Cleanup
	ft_destroy(&data); // Destroys mutexes
	ft_free(&data); // Frees memory
	return (0);
}