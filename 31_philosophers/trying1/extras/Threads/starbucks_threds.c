#include <stdio.h>      // para printf
#include <unistd.h>     // para sleep
#include <pthread.h>    // para threads (pthread)
#include <stdlib.h>     // para exit

void	*make_coffee(void *data)
{
	printf("Barista preparing coffee\n"); /* format */
	sleep(2); /* seconds */
	printf("coffee ready!\n"); /* format */
	return NULL;
}

/*int main()
{
	pthread_t	barista_1;
	pthread_t	barista_2;	

	pthread_create(&barista_1, NULL, make_coffee, NULL); // newthread: attr: start_routine: arg
	pthread_create(&barista_2, NULL, make_coffee, NULL);

	pthread_join(barista_1, NULL);
	pthread_join(barista_2, NULL);
}*/

int main()
{
	pthread_t baristas[500]; // vetor para armazenar os identificadores das 500 threads

	for (int i = 0; i < 500; ++i)
	{
		if (pthread_create(baristas + i, NULL, make_coffee, NULL))
			exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 500; ++i)
	{
		printf("Identifier-> %lu\n", baristas[i]);
	}
	/* Aqui o programa aguarda cada uma das 500 threads terminarem antes 
	de finalizar. pthread_join bloqueia a execução principal até que a 
	thread correspondente termine. */
	for (int i = 0; i < 500; ++i)
		pthread_join(baristas[i], NULL); // evita leaks
	/* Esperar que uma thread termine antes de continuar o programa. */
}