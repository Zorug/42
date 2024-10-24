#include <stdio.h>
#include "libft.h"

int main()
{
    char source[] = "Hello, World!"; // String de origem
    char destination[20]; // Buffer de destino com espaço suficiente

    // Copia 13 bytes de source para destination
    ft_memcpy(destination, source, 13); // Copia a string completa
    destination[13] = '\0'; // Adiciona o terminador nulo

    printf("Copia: %s\n", destination); // Imprime a string copiada

    // Teste de cópia com menos bytes
    char partial_source[] = "Partial Copy";
    char partial_destination[20];
    ft_memcpy(partial_destination, partial_source, 7); // Copia "Partial"
    partial_destination[7] = '\0'; // Adiciona o terminador nulo
    printf("Copia parcial: %s\n", partial_destination); // Imprime a cópia parcial

    // Teste de cópia com ponteiros nulos
    char *null_source = NULL;
    char *null_destination = NULL;
    void *result = ft_memcpy(null_destination, null_source, 5); // Deve retornar NULL
    if (result == NULL) {
        printf("Copia de ponteiros nulos retornou NULL como esperado.\n");
    }

    return 0; // Retorna 0 para indicar que o programa te
}