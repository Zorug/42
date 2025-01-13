#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line() {
    char *line = NULL;
    size_t len = 0;

    printf("Digite uma linha de texto: ");
    getline(&line, &len, stdin);

    return line;
}

int main() {
    char *line = read_line();

    printf("Você digitou: %s", line);

    free(line);
    return 0;
}
