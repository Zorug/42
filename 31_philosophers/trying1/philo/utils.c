#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

/*
	gettimeofday

	time_code -> SECONDS MILLISECONDS MICROSECONS
*/
long	gettime(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeofday failed");
	if (SECOND == time_code)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == time_code)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("Wrong input to gettime!");
	return (1337);
}

/*
	precise usleep, the real one suck

	why Table? Is the simlation finished?

	1) usleep the majority of time, not CPU intensive
	2) refine last microsec with spinlock
*/
void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;

	start = gettime(MICROSECOND);
	while (gettime(MILLISECOND) - start < usec)
	{
		// 1)
		if (simulation_finished(table))
			break ;
		elapsed = gettime(MICROSECOND) - start;
		rem = usec - elapsed;

		//to get a spinlock threshold
		if (rem > 1e3)
			usleep(usec / 2);
		else
		{
			//SPINLOCK
			while (gettime(MICROSECOND) - start < usec)
				;
		}
	}
}

void	error_exit(const char *error)
{
	printf(RED"%s\n"RST, error);
	exit(EXIT_FAILURE);
}