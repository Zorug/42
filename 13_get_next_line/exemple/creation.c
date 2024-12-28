#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h> // Include this for strlen()

int main() {
    int fd;

    // Open the file with write permissions (create if it doesn't exist)
    fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error creating file");
        return 1;
    }

    // Write some content to the file
    const char *content = "Hello, this is a test file.\nEach line has some text.\nThis file is for testing purposes.\nMake sure to read all lines correctly.\nGood luck with your project!\n";
    write(fd, content, strlen(content)); // Use strlen() to get the actual length of the string

    // Close the file
    close(fd);

    printf("File created and written successfully.\n");
    return 0;
}
