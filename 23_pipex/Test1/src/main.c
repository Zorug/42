# include "pipex.h"

/*int main()
{
	ft_printf("Hello World!\n");
}*/

//#include <stdio.h>

/*int main(int argc, char **argv, char **envp)
{
	int i = 0;
	while (envp[i])
	{
		ft_printf("%s\n", envp[i]);
		i++;
	}
	i=0;
	while (argv[i])
		i++;
	i = argc;
	return (0);
}*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>   // já está incluso (ótimo!)
#include <unistd.h>     // necessário para fork, pipe, dup2
#include <sys/types.h>  // boa prática para usar pid_t, wait, etc.



void runpipe();

int main()
{
	int pid, status;
	int fd[2];

	pipe(fd);

	switch (pid = fork()) {

	case 0: /* child */
		runpipe(fd);
		exit(0);

	default: /* parent */
		while ((pid = wait(&status)) != -1)
			fprintf(stderr, "process %d exits with %d\n", pid, WEXITSTATUS(status));
		break;

	case -1:
		perror("fork");
		exit(1);
	}
	exit(0);
}

char *cmd1[] = { "/bin/ls", "-al", "/", 0 };
char *cmd2[] = { "/usr/bin/tr", "a-z", "A-Z", 0 };

void runpipe(int pfd[])
{
	int pid;

	switch (pid = fork()) {
	case 0: /* child */
		dup2(pfd[0], 0);
		close(pfd[1]);
		execvp(cmd2[0], cmd2);
		perror(cmd2[0]);
		exit(1);  // ← evita queda no switch
	default: /* parent */
		dup2(pfd[1], 1);
		close(pfd[0]);
		execvp(cmd1[0], cmd1);
		perror(cmd1[0]);
		exit(1);  // ← evita queda no switch
	case -1:
		perror("fork");
		exit(1);
	}
}
