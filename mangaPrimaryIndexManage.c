//
// Created by Luiz Tavares on 12/06/24.
//


#include <stdio.h>
#include <stdlib.h>
#include "mangaPrimaryIndexManege.h"
#include "mangaDataFileManage.h"
#define NamePrimaryKeyFile "manga_primary_key_file.txt"

void moveDataAndInsertNewDataInPrimaryDataFile(FILE *filePointer,long indexToInsert,char *stringToInsert){
    //Pegar posição do ultimo elemento no arquivo
    fseek(filePointer,0,SEEK_END);

    long final_index = ftell(filePointer);
    long numElements = final_index-indexToInsert;

    //Criar buffer com o tamanho dos dados a partir de onde queremos inserir o novo
    char buffer[numElements];

    // Movemos o ponteiro para a posição que queremos inserir
    fseek ( filePointer , indexToInsert, SEEK_SET );

    // Lemos os dados a seguir dessa posição para salvar os dados
    fread(buffer, sizeof(char), numElements, filePointer);
    // Inserimos caracter de fim para se tornar uma string valida
    buffer[numElements] = '\0';

    //Voltar o ponteiro para a posição desejada
    fseek ( filePointer , indexToInsert , SEEK_SET );

    //Inserindo novos valores
    fputs (stringToInsert, filePointer );

    //Inserindo dados salvos no buffer
    fprintf(filePointer,"%s",buffer);
}

void SeachAndInsertNewPrimaryKeyOrderly(long indexInDataFile,char* primarykey) {
    FILE *filePointer = fopen(NamePrimaryKeyFile, "r+");
    if (filePointer == NULL) {
        perror("Erro ao abrir o arquivo");
    }
    long inicio = 0;
    long fim = 0;
    long fimbackup = 0;

    char buffer[100];
    int charValue;

    while ((charValue = fgetc(filePointer)) != EOF) {
        char character = (char) charValue;

        if (character == ':') {
            inicio = ftell(filePointer);  // Salva a posição após ':'
        }

        if (character == '|') {
            fim = ftell(filePointer);  // Salva a posição após '|'

            fseek(filePointer, inicio, SEEK_SET);  // Move o ponteiro de volta para inicio

            size_t tamanho = fim - inicio - 1;  // Calcula o tamanho do buffer (desconta '|')

            fread(buffer, sizeof(char), tamanho, filePointer);  // Lê os dados para o buffer
            buffer[tamanho] = '\0';  // Adiciona terminador nulo para imprimir como string

            int valor_buffer = atoi(buffer);
            if (valor_buffer < indexInDataFile) {
                fimbackup = fim;
            }

            if (valor_buffer > indexInDataFile) {
                moveDataAndInsertNewDataInPrimaryDataFile(filePointer, fimbackup, primarykey);
                fclose(filePointer);
                return;
            }

            fseek(filePointer, fim, SEEK_SET);  // Move o ponteiro de volta para após '|'

            inicio = 0;
            fim = 0;
        }

    }
    fseek(filePointer, 0, SEEK_END);
    fputs (primarykey, filePointer);
    fclose(filePointer);
}
