#include <stdio.h>
#include <string.h>
#include "libft.h"

void my_function(unsigned int i, char *c)
{
    *c = *c + i;  // Incrementa o caractere pelo valor do índice (exemplo simples)
}

int main(void)
{
    char str[] = "Hello";
    ft_striteri(str, my_function);
    printf("Resultado: %s\n", str);
    return 0;
}