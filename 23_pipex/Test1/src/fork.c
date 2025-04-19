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

int main()
{
	pid_t pid;

	pid = 9;
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Hello1, I am main process (before fork). My PID is %d.\n", getpid());
	// Create a child process using fork()
	pid = fork();
	printf("------------------------------------\n");     
    printf("Hello1, I am main process (after fork). My PID is %d.\n", getpid());	
	if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork2 failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello1, I am the child process! My PID is %d, and my child's PID is %d\n", getpid(), pid);
    } else {
        // Parent process
        printf("Hello1, I am the parent process! My PID is %d, and my child's PID is %d.\n", getpid(), pid);
    }

    return 0;
}