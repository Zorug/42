/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:12:01 by cgross-s          #+#    #+#             */
/*   Updated: 2025/05/18 10:31:07 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>

# define ROSE "\x1b[38;207;1m"
# define ROSE_2 "\x1b[38;5;177;1m"
# define LIGHTGREEN "\x1b[38;5;155;1m"
# define LIGHTBLUE "\x1b[38;5;39;1m"
# define LIGHTPURPLE "\x1b[38;5;63;1m"
# define PURPLE "\x1b[38;5;135;1m"
# define PINK "\x1b[38;5;199;1m"
# define RED "\x1b[38;5;160;1m"
# define ORANGE "\x1b[38;5;172;1m"
# define YELLOW "\x1b[38;5;184;1m"
# define COLOR_RESET "\x1b[0m"

# define EAT "🍝 is eating\n"
# define SLEEP "is sleeping 💤\n"
# define THINK "is thinking 💭\n"
# define FORK "has taken a fork 🍴\n"
# define DIE "died 💀\n"
# define FULL "ALL PHILOSOPHERS ARE FULL! 😋\n"

// # define EAT "is eating\n" 
// # define SLEEP "is sleeping\n" 
// # define THINK "is thinking\n" 
// # define FORK "has taken a fork\n" 
// # define DIE "died\n" 
// # define FULL ORANGE "ALL PHILOSOPHERS ARE FULL!\n" 

typedef struct s_philo
{
	pthread_t		thread;			// Thread for this philosopher
	size_t			id;				// Philosopher ID number
	size_t			last_meal;		// Timestamp of last meal
	int				meals_eaten;	// Number of meals consumed
	int				is_eating;		// Flag indicating eating state
	int				*death;			// Pointer to shared death flag
	pthread_mutex_t	*dead_lock;		// Mutex for death flag
	pthread_mutex_t	*meal_lock;		// Mutex for meal tracking
	pthread_mutex_t	*write_lock;	// Mutex for output
	pthread_mutex_t	*r_fork;		// Right fork mutex
	pthread_mutex_t	*l_fork;		// Left fork mutex
	struct s_data	*data;			// Pointer to shared data
}	t_philo;

typedef struct s_data
{
	int				philo_nbr;		// Number of philosophers
	size_t			time_to_die;	// Time before starving (ms)
	size_t			time_to_sleep;	// Sleep duration (ms)
	size_t			time_to_eat;	// Eating duration (ms)
	int				nbr_of_meals;	// Optional meal limit (-1 if none)
	size_t			start;			// Simulation start time
	int				death;			// Flag indicating if someone died
	pthread_mutex_t	dead_lock;		// Mutex for death flag
	pthread_mutex_t	meal_lock;		// Mutex for meal tracking
	pthread_mutex_t	write_lock;		// Mutex for output
	pthread_mutex_t	*forks;			// Array of fork mutexes
	t_philo			*philos;		// Array of philosophers
}	t_data;

/* utils */


/* init */


/* main */


/* destroy */


/* routine */


/* checkers */


/* philo */


#endif