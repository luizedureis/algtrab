#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define INITIAL_BUFFER_SIZE 10

char* readStringFromInput() {
    int bufferSize = INITIAL_BUFFER_SIZE;
    char *buffer = (char *)malloc(bufferSize * sizeof(char));
    if (buffer == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    int position = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Se o buffer estiver cheio, redimensione-o
        if (position >= bufferSize - 1) {
            bufferSize *= 2;
            char *newBuffer = (char *)realloc(buffer, bufferSize * sizeof(char));
            if (newBuffer == NULL) {
                printf("Erro na re-alocação de memória.\n");
                free(buffer);  // Libera a memória original em caso de falha
                exit(1);
            }
            buffer = newBuffer;
        }

        buffer[position++] = ch;
    }
    buffer[position] = '\0';  // Adiciona o terminador nulo no final

    return buffer;
}
void flush_in() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
long returnLastIndexInDataFile(FILE *filePointer){
    return ftell(filePointer);
}
