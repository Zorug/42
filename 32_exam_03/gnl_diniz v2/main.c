#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*line;

	if (fd == -1)
		return (perror("open"), 1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

/*
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c main.c -o gnl_test
./gnl_test
*/