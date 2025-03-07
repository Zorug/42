#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 10  // Define quantos bytes ler por vez

char *read_line()
{
    char *buffer = NULL;
    char temp[BUFFER_SIZE + 1];  // Buffer temporário para leitura
    int total_len = 0;
    int bytes_read;

    while ((bytes_read = read(0, temp, BUFFER_SIZE)) > 0)
    {
        temp[bytes_read] = '\0'; // Garante que temp seja uma string válida
        char *new_buffer = realloc(buffer, total_len + bytes_read + 1);
        if (!new_buffer) // Falha na alocação
        {
            free(buffer);
            return NULL;
        }
        buffer = new_buffer;
        for (int i = 0; i < bytes_read; i++)
        {
            buffer[total_len + i] = temp[i];
            if (temp[i] == '\n') // Parar quando encontrar '\n' (Enter)
            {
                buffer[total_len + i + 1] = '\0';
                return buffer;
            }
        }
        total_len += bytes_read;
        buffer[total_len] = '\0';
    }

    return buffer; // Retorna a string lida
}

int ft_strcnt(char *str)
{
	int i;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int main()
{
    char *str0;// = "Digite algo: ";
    char *input;

    str0 = "Digite algo: ";
    write(1, str0, ft_strcnt(str0));
    //char *input = read_line();
    input = read_line();
    
    if (input)
    {
        printf("Você digitou: %s", input);
        free(input); // Libera a memória alocada
    }
    else
    {
        printf("Erro ao ler entrada!\n");
    }

    return 0;
}
