#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char **result = ft_split("###42 São#Paulo##é#incrível##", '#');
    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
            printf("Substring %d: %s\n", i, result[i]);
        
        // Libera cada substring e o array
        for (int i = 0; result[i] != NULL; i++)
            free(result[i]);
        free(result);
    }
    else
    {
        printf("Falha na alocação de memória.\n");
    }

    return 0;
}