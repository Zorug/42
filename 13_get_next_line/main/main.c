#include <fcntl.h>   // Para open()
#include <unistd.h>  // Para close()
#include <stdio.h>   // Para printf()
#include <stdlib.h>  // Para free()
#include "get_next_line.h" // Seu arquivo header

/*int main(int argc, char **argv) {
    int fd;
    char *line;

    // Verifica se um arquivo foi passado como argumento
    if (argc == 2) {
        fd = open(argv[1], O_RDONLY); // Abre o arquivo em modo leitura
        if (fd < 0) {
            perror("Erro ao abrir o arquivo");
            return 1;
        }
    } else {
        // Se nenhum arquivo foi passado, usa a entrada padrão (stdin)
        printf("Digite texto (Ctrl+D para finalizar):\n");
        fd = 0; // stdin
    }

    // Lê e imprime as linhas do arquivo ou da entrada padrão
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linha: %s", line);
        free(line); // Libera a memória alocada para a linha
    }

    if (fd != 0) {
        close(fd); // Fecha o arquivo se não for stdin
    }

    return 0;
}*/


#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
