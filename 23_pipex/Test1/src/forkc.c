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

/*int main()
{
	char *const args[] = {"ls", NULL}; // the command
	char *const envp[] = {NULL}; // env

	execve("/usr/bin/ls", args, envp); // execute command at path

	perror("execve");
	//ft_printf("PID AFTER the execve is: %d\n", getpid());
	printf("PID AFTER the execve is: %d\n", getpid()); //why is this not getting printed?
	return 1;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	pid_t   pid;
	int pfd[2];

	pipe(pfd);
	pid = fork();
	if (pid < 0) 
	{
		fprintf(stderr, "Fork2 failed.\n");
		return 1;
	}
	else if (pid == 0)
	{
		close(pfd[0]); //close unused end (the reading end) of the pipe
		write(pfd[1], "this is a new message", 22);  
		close(pfd[1]); //close after writing into the pipe
				exit(EXIT_SUCCESS);     
	}
	else
	{
		close(pfd[1]); //close unused end (the writing end) of the pipe
		char  str[22];
		read(pfd[0], str, 22);
		printf("Parent received:%s\n", str);
		close(pfd[0]); //close after reading from the pipe
		wait(NULL);
	}
	return EXIT_SUCCESS;
}

