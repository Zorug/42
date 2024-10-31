#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
    char *original = "42 São Paulo";
    char *copia = ft_strdup(original);

    if (!copia)
    {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    printf("Original: %s\n", original);
    printf("Cópia: %s\n", copia);

    free(copia);  // Libera a memória alocada para a cópia
    return 0;
}