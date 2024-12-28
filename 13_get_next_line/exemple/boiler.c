#include <fcntl.h>    // For open() and O_RDONLY
#include <unistd.h>   // For close()
#include <stdio.h>    // For printf()

int main() {
    int 	fd;
    char	buf[256];
    int		chars_read;

    // Open the file in read-only mode
    fd = open("file.txt", O_RDONLY);

    while ((chars_read = read(fd, buf, 25)))
    {
    	buf[chars_read] = '\0';
    	printf("buf-> %s\n", buf);
    }
}
