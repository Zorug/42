
#ifndef PIPEX_H
# define PIPEX_H

//#include <stdio.h>
//#include <unistd.h>
# include "../libft/libft.h"
//# include "../libft/ft_printf.h"


# include <unistd.h>     // read, write, fork, pipe, dup, dup2, access, execve, close, unlink
# include <stdlib.h>     // malloc, free, exit
# include <fcntl.h>      // open, O_RDONLY, O_CREAT, etc.
# include <sys/wait.h>   // wait, waitpid, macros WEXITSTATUS etc.
# include <sys/types.h>  // usado com wait, pid_t
# include <stdio.h>      // perror
# include <string.h>     // strerror, (às vezes strlen, etc.)


#endif