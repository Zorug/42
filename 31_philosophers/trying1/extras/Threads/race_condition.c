#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#define TH	100
/* Simular 100 threads (TH = 100) que todas acessam e atualizam uma 
variável compartilhada (ledger), com proteção contra concorrência usando 
um mutex (ledger_lock). */

// file Shared resource
/* é a variável compartilhada entre todas as threads. */
uint64_t	ledger = 0; /* tipo de dado inteiro definido no cabeçalho <stdint.h>. Ele representa um inteiro sem sinal (unsigned) de 64 bits */
/* ledger_lock é um mutex (trava) que protege o acesso a ledger. */
pthread_mutex_t	ledger_lock = PTHREAD_MUTEX_INITIALIZER;

/*  Isso evita que duas threads modifiquem ledger ao mesmo tempo, 
o que causaria uma condição de corrida (race condition). */
void	*update_ledger(void *data)
{
	pthread_mutex_lock(&ledger_lock);
	ledger += 1;
	pthread_mutex_unlock(&ledger_lock);
	return NULL;
}

int main ()
{
	pthread_t	waiters[TH];

	//pthread_mutex_init(&ledger_lock, NULL);
	for (int i = 0; i < TH; ++i)
	{
		if (pthread_create(waiters + i, NULL, update_ledger, NULL))
			exit(EXIT_FAILURE);
	}
	for (int i = 0; i < TH; ++i)
		pthread_join(waiters[i], NULL);
	printf("\t%lu\n", ledger);
}