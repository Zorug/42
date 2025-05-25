#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>

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
	pthread_t		thread;
	size_t			id;
	size_t			last_meal;
	int				meals_eaten;
	int				is_eating;
	int				*death;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_nbr;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	int				nbr_of_meals;
	size_t			start;
	int				death;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

//utils
size_t	ft_strlen(char *str);
long	ft_atoi(char *nbr);
size_t	get_time(void);
int		is_number(char *str);
int		ft_usleep(size_t milliseconds);
int		death_loop(t_philo *philo);
void	ft_destroy(t_data *data);
//init
void	init_philos(t_data *data, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, size_t nbr_philos);
void	init_data(t_data *data, t_philo *philos, char **argv, char argc);
//main
void	one_philo(t_data *data, t_philo *philo);
int		check_args(char **argv);
//destroy
void	ft_free(t_data *data);
void	ft_destroy(t_data *data);
//routine
void	*routine(void *pointer);
//checkers
int		death_loop(t_philo *philo);
int		check_meals(t_philo *philos);
int		is_dead(t_philo *philo);
int		check_death(t_philo *philo);
//philo
void	print_message(char *str, t_philo *philo);
int		create_threads(t_data *data, t_philo *philos);

#endif