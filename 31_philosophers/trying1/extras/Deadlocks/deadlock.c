#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

/*	Cada cowboy tem sua arma exclusiva representada por um mutex.
	Esses mutex simulam recursos exclusivos que só um pode usar por vez. */
//GUNS
pthread_mutex_t ugly_gun = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t bad_gun = PTHREAD_MUTEX_INITIALIZER;

typedef struct s_cowboy
{
	char			*name;
	unsigned long	reaction_time;
	pthread_t		thread; /* representa o cowboy em execução paralela */
}	t_cowboy;

void	*action(void *data)
{
	t_cowboy	cowboy;

	cowboy = *(t_cowboy *)data;

	// How fast the cowboy is
	printf("!! %s reaction_time %lu !!\n", 
		cowboy.name, cowboy.reaction_time);
	/* 	Simula o tempo de reação do cowboy. 
		O mais rápido "acorda" primeiro. */
	usleep(cowboy.reaction_time);

	/*	O cowboy pega sua própria arma primeiro.
    	Depois tenta pegar a do outro.
💥 Aqui mora o perigo:
Se ambos os cowboys fizerem isso ao mesmo tempo (cada um com sua 
arma, esperando pela outra), o programa trava para sempre — isso 
é um deadlock. */
	if (!strcmp(cowboy.name, "ugly"))
		pthread_mutex_lock(&ugly_gun);
	else
		pthread_mutex_lock(&bad_gun);
	printf("%s has taken his own gun\n", cowboy.name);

	// I wanna take the other gun
	// DEADLOCK
	if (!strcmp(cowboy.name, "ugly"))
		pthread_mutex_lock(&bad_gun);
	else
		pthread_mutex_lock(&ugly_gun);

	// The killer will reach this position
	printf("|| %s killed the other ||\n", cowboy.name);
	exit(EXIT_SUCCESS);

	return NULL;
}

int main()
{
	srand(time(NULL) * getpid());
	t_cowboy	ugly = {"ugly", rand() % 10000};
	t_cowboy	bad = {"bad", rand() % 10000};

	pthread_create(&ugly.thread, NULL, action, &ugly);
	pthread_create(&bad.thread, NULL, action, &bad);

	pthread_join(ugly.thread, NULL);
	pthread_join(bad.thread, NULL);
}