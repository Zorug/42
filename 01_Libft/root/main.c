#include <stdio.h>
#include <string.h>
#include "libft.h"

char my_function(unsigned int i, char c)
{
    return (c + i);  // Adiciona o índice ao caractere (exemplo simples)
}

int main(void)
{
    char *result = ft_strmapi("Hello", my_function);
    if (result)
    {
        printf("Resultado: %s\n", result);
        free(result);  // Libera a memória alocada
    }
    return 0;
}