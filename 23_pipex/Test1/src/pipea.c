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
#include <stdio.h> 	/* for printf */
#include <string.h>	/* for strlen */

int main()
{
	int n;
	int fd[2];
	char buf[1025];
	char *data = "hello... this is sample data";

	pipe(fd);
	write(fd[1], data, strlen(data));
	if ((n = read(fd[0], buf, 1024)) >= 0)
	{
		buf[n] = 0;	/* terminate the string */
		printf("read %d bytes from the pipe: \"%s\"\n", n, buf);
	}	
	else
		perror("read");
	exit(0);
}