//
// Created by Luiz Tavares on 21/06/24.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// Função para encontrar e remover uma string do arquivo
void removeStringFromFile(const char *filePath, const char *searchString) {
    FILE *file = fopen(filePath, "r+");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Obter o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Alocar memória para o conteúdo do arquivo
    char *fileContent = (char *)malloc(fileSize + 1);
    if (fileContent == NULL) {
        perror("Erro ao alocar memória");
        fclose(file);
        return;
    }

    // Ler o conteúdo do arquivo
    fread(fileContent, 1, fileSize, file);
    fileContent[fileSize] = '\0'; // Adicionar caractere nulo ao final

    // Encontrar a string no conteúdo do arquivo
    char *position = strstr(fileContent, searchString);
    if (position != NULL) {
        // Calcular a posição inicial e final da string
        long startIndex = position - fileContent;
        long endIndex = startIndex + strlen(searchString);

        // Mover o conteúdo após a string para a posição inicial
        memmove(fileContent + startIndex, fileContent + endIndex, fileSize - endIndex + 1);

        // Truncar o arquivo e escrever o conteúdo atualizado
        freopen(filePath, "w", file);
        fwrite(fileContent, 1, strlen(fileContent), file);

        printf("String removida do arquivo.\n");
    } else {
        printf("String não encontrada no arquivoooo.\n");
    }

    // Liberar a memória e fechar o arquivo
    free(fileContent);
    fclose(file);
}

// Função para encontrar a string, localizar o '#', substituir o próximo caractere por '*' e retornar seu índice
int replaceCharAfterHashBeforeString(const char *filePath, const char *searchString) {
    FILE *file = fopen(filePath, "r+");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    // Obter o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Alocar memória para o conteúdo do arquivo
    char *fileContent = (char *)malloc(fileSize + 1);
    if (fileContent == NULL) {
        perror("Erro ao alocar memória");
        fclose(file);
        return -1;
    }

    // Ler o conteúdo do arquivo
    fread(fileContent, 1, fileSize, file);
    fileContent[fileSize] = '\0'; // Adicionar caractere nulo ao final

    // Encontrar a posição da string no conteúdo do arquivo
    char *position = strstr(fileContent, searchString);
    if (position == NULL) {
        printf("String não encontrada no arquivo.\n");
        free(fileContent);
        fclose(file);
        return -1;
    }

    // Encontrar o primeiro '#' antes da string
    char *hashPosition = position;
    while (hashPosition > fileContent && *hashPosition != '#') {
        hashPosition--;
    }

    if (*hashPosition != '#') {
        printf("Nenhum '#' encontrado antes da string.\n");
        free(fileContent);
        fclose(file);
        return -1;
    }

    // Substituir o próximo caractere por '*'
    if (hashPosition + 1 <= fileContent + fileSize) {
        *(hashPosition + 1) = '*';
    } else {
        printf("Não há próximo caractere para substituir.\n");
        free(fileContent);
        fclose(file);
        return -1;
    }

    // Calcular e retornar o índice do caractere substituído em relação ao início do arquivo
    int index = hashPosition + 1 - fileContent;

    // Truncar o arquivo e escrever o conteúdo atualizado
    freopen(filePath, "w", file);
    fwrite(fileContent, 1, strlen(fileContent), file);

    // Liberar a memória e fechar o arquivo
    free(fileContent);
    fclose(file);

    return index;
}

void removeMainProcess(){
    char *autorAux, *tituloAux, *auxAux, *lastAux, *firstAux;
    const char *filepath1 = "manga_secundary_key_file.txt";
    const char *filepath2 = "manga_data_file.txt";
    const char *filepath3 = "manga_primary_key_file.txt";

    autorAux = (char *) malloc(100 * sizeof(char));
    tituloAux = (char *) malloc(100 * sizeof(char));
    auxAux = (char *) malloc(100 * sizeof(char));
    lastAux = (char *) malloc(100 * sizeof(char));
    firstAux = (char *) malloc(100 * sizeof(char));

    printf("Autor a ser deletado: ");
    scanf("%s", autorAux);
    printf("Titulo a ser deletado: ");
    scanf("%s", tituloAux);

    sprintf(auxAux, "%s|%s", tituloAux, autorAux);
    int k = replaceCharAfterHashBeforeString(filepath2, auxAux);

    sprintf(lastAux, "%s:%d|", tituloAux, k);
    removeStringFromFile(filepath3, lastAux);

    sprintf(firstAux, "%s:%s|", autorAux, tituloAux);
    removeStringFromFile(filepath1, firstAux);
    free(autorAux);
    free(tituloAux);
    free(auxAux);
    free(lastAux);
    free(firstAux);
}