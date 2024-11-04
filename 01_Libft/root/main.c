#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    int num = 0;
    char *str = ft_itoa(num);

    if (str)
    {
        printf("\nO número como string é: %s\n", str);
        free(str);  // Libera a memória alocada para a string
    }
    else
    {
        printf("Falha na alocação de memória.\n");
    }

    return 0;
}