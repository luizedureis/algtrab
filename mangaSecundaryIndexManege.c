//
// Created by Luiz Tavares on 13/06/24.
//

#include "mangaDataFileManage.h"
#include <string.h>
#define NameSecundaryKeyFile "manga_secundary_key_file.txt"
#define NotFount -1

long checkIfSecundaryKeyAlreadyExist(FILE *filePointer,char *autor){
    long inicio;
    long fim;
    char character;

    char buffer[50];
    inicio = fim = 0;
    while ((character = fgetc(filePointer)) != EOF) {
        if (character==':'){
            fim = ftell(filePointer);
            fseek(filePointer, inicio, SEEK_SET);

            long numElementos = fim-inicio-1;

            buffer[numElementos];
            fread(buffer, sizeof(char), numElementos, filePointer);  // Lê os dados para o buffer
            buffer[numElementos] = '\0';

            fseek(filePointer, fim, SEEK_SET);  // Move o ponteiro de volta para inicio
            if(strcmp(buffer, autor)==0){
                return inicio;
            }
        }
        if(character == '|'){
            inicio = ftell(filePointer);
        }
    }
    return NotFount;
}

void moveDataAndInsertNewDataInSecundaryDataFile(FILE *filePointer,long indexToInsert,char *stringToInsert) {
    fseek ( filePointer , 0, SEEK_END );

    long fim = ftell(filePointer);
    long numElements = fim-indexToInsert;
    char buffer[numElements];

    fseek ( filePointer , indexToInsert, SEEK_SET );

    fread(buffer, sizeof(char), numElements, filePointer);
    buffer[numElements] = '\0';
    fseek ( filePointer , indexToInsert , SEEK_SET );

    fputs (stringToInsert, filePointer );
    fprintf(filePointer,"%s",buffer);

}

int insertNewDataInSecundaryIndexFile(Manga *manga){
    FILE *filePointer = fopen(NameSecundaryKeyFile,"r+");
    long response = checkIfSecundaryKeyAlreadyExist(filePointer,manga->autores);
    char final[50];
    sprintf(final, "%s:%s|",manga->autores, manga->titulo);
    if (response == NotFount) {
        fseek(filePointer,0,SEEK_END);
        moveDataAndInsertNewDataInSecundaryDataFile(filePointer,ftell(filePointer),final);
    }else{
        moveDataAndInsertNewDataInSecundaryDataFile(filePointer,response,final);
    }
    fclose(filePointer);
}