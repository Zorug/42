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
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void    callexecve()
{
	char *const args[] = { "ls", NULL };
	char *const envp[] = { NULL };
	
	execve("/usr/bin/ls", args, envp);
	perror("execve");
		exit(EXIT_FAILURE); // Make sure to exit the child process if execve fails 
}

int main(void)
{
	pid_t pid;
	
	printf("Hi I am the main process. My PID is :%d\n", getpid());
	pid = fork();
	if (pid == -1)
		printf("Error while forking\n");
	else if (pid == 0)
	{
		printf("I am the child. But now a new parent. My PID is :%d --- My child's PID is %d\n", getpid(), pid);
		callexecve();
	}
	else if (pid > 1)
	{
		printf("I am the parent. My PID is :%d --- My child's PID is %d\n", getpid(), pid);
		waitpid(pid, NULL, 0); 
		printf("Got back the control?\n");
	}
 }

