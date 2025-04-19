#include "pipex.h"

/*  
DEF: Outputs the string ’s’ to the given file descriptor.
RETURN VALUE: None.
*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}