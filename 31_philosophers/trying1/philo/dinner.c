#include "philo.h"

//todo
static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo, DEBUG_MODE);
}

/*
	eat routine

	1) grab the forks : here first & second fork is handy
		i dont worry about left right
	2) eat : write eat, update last meal, update meals counter
		eventually bool full
	3) releas the forks
*/
static void	eat(t_philo *philo)
{
	// 1)
	safe_mutex_handle(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex_handle(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);

	// 2)
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);

	// 3
	safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

/*
	0) wait all philos, synchro start

	1) endless loop philo
*/

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;

	wait_all_threads(philo->table);

	// set last meal time


	while (!simulation_finished(philo->table))
	{
		// 1) am i full?
		if (philo->full) //todo thread safe
			break;

		// 2) eat
		eat(philo);

		// 3) sleep ->write satus & precise usleep
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->time_to_sleep, philo->table);

		// 4) think
		thinking(philo); //todo
	}
}

/*
	actual meat

	./philo 5 800 200 200 [5]

	0) If no meals, return -> [0]
	0.1) If only one philo-> ad hoc function
	1) Create all threads, all philos
	2) Create a monitor thread -> death
	3) Synchronize the beggining of the simulation
		pthread_create-> philo starts running!
		every philo start simultaneously
	4) JOIN everyone
*/

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (0 == table->nbr_limit_meals)
		return ; // back to main, clean
	else if (1 == table->philo_nbr)
		; //todo
	else
	{
		while (++i < table->philo_nbr)
			safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
			&table->philos[i], CREATE);
	}

	// start of simulation
	table->start_simulation = gettime(MILLISECOND);

	// now all threads are ready
	set_bool(&table->table_mutex, &table->all_threads_ready, true);

	// Wait for everyone
	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);

	// If we manage to reach this line, all philos are FULL!
}