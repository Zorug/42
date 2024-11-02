#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
    char *s1 = "*_ 01234 * _";
    char *set = " *_";
    char *trimmed = ft_strtrim(s1, set);

    if (trimmed)
    {
        printf("Resultado: '%s'\n", trimmed);
        free(trimmed);
    }
    else
    {
        printf("Falha na alocação de memória.\n");
    }

    return 0;
}