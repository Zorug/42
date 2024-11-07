#include "libft.h"


int main()
{
	char src[50] = "This is the source string.";
    //char *src = NULL; // zsh: segmentation fault (core dumped)
    //char dst[50];
    char *dst = NULL; //Destino: (null)

    ft_memcpy(dst, src, ft_strlen(src) + 1);  // Copia a string com o terminador nulo

    printf("Destino: %s\n", dst);  // Saída esperada: "This is the source string."

    return 0;
}