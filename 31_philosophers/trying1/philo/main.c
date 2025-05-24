#include "philo.h"

/*
	The main is a TL;DR of the program
	./philo 5 800 200 200 [5]
*/

int main(int ac, char **av)
{
	t_table table;

	if (5 == ac || 6 == ac)
	{
		// correct input
		//1) errors checking, filling table table
		parse_input(&table, av);

		//2) creating the actual thing
		//data_init(&table);

		//3)
		//dinner_start(&table);

		//4) No leaks
		//clean(&table);

	}
	else
	{
		// error
		error_exit("Wrong input:\n"
					G"Correct is ./philo 5 800 200 200 [5]"RST);
	}
}

/*
Visualizador do philosophers:
https://nafuka11.github.io/philosophers-visualizer/
*/