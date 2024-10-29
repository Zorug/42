#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
    char destination[20] = "123456";
    const char *source = "7890";
    size_t total_length;

    total_length = ft_strlcat(destination, source, sizeof(destination));
    printf("Concatenated string: %s\n", destination);
    printf("Total length: %zu\n", total_length);
    return (0);
}