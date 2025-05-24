#include <stdio.h>		// printf
#include <stdlib.h>		// malloc, free
#include <unistd.h>		// write, usleep
#include <stdbool.h>
#include <pthread.h>  	/*mutex: 	init, destroy, lock, unlock	
						threads:	create, join, detach*/
#include <sys/time.h> 	// gettimeofday
#include <limits.h> //INT_MAX
#include <errno.h>


/*
	ANSI Escape Sequence for BOld Text Color
	Usage:
		printf(R "This is red text." RST);
		printf(B "This is blue text." RST);
	Remeber to use RST to reset the color after setting it.
*/

#define RST			"\033[0m" /* Reset to default color */
//#define BOLD_BLACK   "\033[1;30m"
#define RED			"\033[1;31m" /* Bold Red */
#define G			"\033[1;32m" /* Bold Green */
#define Y			"\033[1;33m" /* Bold Yellow */
#define B			"\033[1;34m" /* Bold Blue */
#define M			"\033[1;35m" /* Bold Magenta */
#define C			"\033[1;36m" /* Bold Cyan */
#define W			"\033[1;37m" /* Bold White */

/* write function macro */
#define DEBUG_MODE 0
/*
	PHILO STATES
*/
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED
}	t_philo_status;

/* 
	OPCODE for mutex | thread functions
*/

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

/*
	CODES for gettime
*/
typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

/* structures */

/* code more readable */
typedef	pthread_mutex_t	t_mtx;

/* IOU for compiler */
typedef struct s_table t_table;

typedef	struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

/*

	PHILO
	./philo 5 800 200 210 [5]

*/

typedef	struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time; // time passed from last meal
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id; // a philo is a thread
	t_mtx		philo_mutex; // useful for races with the monitor
	t_table		*table;
}	t_philo;


typedef	struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals; // [5] | FLAG if -1
	long	start_simulation; // time
	bool	end_simulation; // a philo dies or all philos full
	bool	all_threads_ready; // to synchro philosophers
	t_mtx	table_mutex; // avoid races while reading from table
	t_mtx	write_mutex;
	t_fork	*forks; // array forks
	t_philo	*philos; // array
}	t_table;

/* utils */
long	gettime(t_time_code time_code);
void	precise_usleep(long usec, t_table *table);
void	error_exit(const char *error);

/* parsing */
void	parse_input(t_table *table, char **av);

/* safe funcions */
void	*safe_malloc(size_t bytes);
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);

/* synchro utils */
void	wait_all_threads(t_table *table);

/* setter andgetter, very useful to write DRY code */
void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
bool	get_long(t_mtx *mutex, long *value);
void	set_long(t_mtx *mutex, long *dest, long value);
bool	simulation_finished(t_table *table);

/* write */
void	write_status(t_philo_status status, t_philo *philo, bool debug);

/* init */
void	data_init(t_table *table);

/*
Visualizador do philosophers:
https://nafuka11.github.io/philosophers-visualizer
*/
