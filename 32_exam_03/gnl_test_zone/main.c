#include <fcntl.h>     // for open()
#include <stdio.h>     // for printf()
#include <stdlib.h>    // for free()
#include <unistd.h>    // for close()

char *get_next_line(int fd);

int main(void)
{
    int     fd = open("testfile.txt", O_RDONLY);
    char    *line;

    if (fd == -1)
        return (perror("open"), 1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}
