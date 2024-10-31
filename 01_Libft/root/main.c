#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
    char *s1 = "42 ";
    char *s2 = "São Paulo";
    char *joined = ft_strjoin(s1, s2);

    if (joined)
    {
        printf("Resultado da junção: %s\n", joined);
        free(joined);  // Libera a memória alocada para a string concatenada
    }
    else
    {
        printf("Falha na alocação de memória.\n");
    }
}