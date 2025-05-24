#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>  // Para wait()

uint64_t	ledger;

int main()
{
	pid_t	pid;

	pid = fork();
	//CHILD
	if (0 == pid)
	{
		ledger += 42;
		printf("CHILD ledger->%lu\n", ledger);
	}
	//I AM UR FATHER
	else
	{
		ledger += 42;
		wait(NULL);
		printf("FATHER ledger->%lu\n", ledger);
	}
}