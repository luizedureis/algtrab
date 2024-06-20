//
// Created by Luiz Tavares on 11/06/24.
//
#include "mangaDataFileManage.h"
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include "mangaPrimaryIndexManege.h"
#include "mangaSecundaryIndexManege.h"
#define MAXCHARLENGH 10
#define NameDataFile "manga_data_file.txt"
#define DELIMITERCHAR '|'
#define DELIMITERREGISTRO '#'


Manga* readFromInput(){
    Manga *manga;
    manga = (Manga *) malloc(sizeof(Manga));

    printf("Insira o ISBN: ");
    manga->ISBN = readStringFromInput();

    printf("Insira o titulo: ");
    manga->titulo = readStringFromInput();

    printf("Insira os autores: ");
    manga->autores = readStringFromInput();

    printf("Insira o ano de inicio: ");
    manga->anoInicio = readStringFromInput();

    printf("Insira o ano de fim: ");
    manga->anoFim = readStringFromInput();

    printf("Insira o genero: ");
    manga->genero = readStringFromInput();

    printf("Insira a revista: ");
    manga->revista = readStringFromInput();

    printf("Insira a editora: ");
    manga->editora = readStringFromInput();

    printf("Insira o ano da edição: ");
    manga->anoDaEdicao = readStringFromInput();

    printf("Insira a lista de volumes adquiridos: ");
    manga->volumesAdquirido = readStringFromInput();

    printf("Insira a quantidade de volumes: ");
    scanf("%d",&manga->qntVolumes);

    printf("Insira a quantidade de volumes adquiridos: ");
    scanf("%d",&manga->qntVolumesAdquiridos);

    printf("\n");
    return manga;
};

long writeDataFile(Manga *manga,FILE *filePointer){
    fseek(filePointer,0,SEEK_END);
    long final_index = ftell(filePointer);

    fprintf(filePointer, "%s", manga->ISBN);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->titulo);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->autores);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->anoInicio);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->anoFim);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->genero);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->revista);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->editora);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->anoDaEdicao);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%d", manga->qntVolumes);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%d", manga->qntVolumesAdquiridos);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%s", manga->volumesAdquirido);
    fputc(DELIMITERCHAR, filePointer);

    fputc(DELIMITERREGISTRO,filePointer);
    return final_index;
}
void deleteManga(Manga *manga){
    free(manga->titulo);
    free(manga->autores);
    free(manga->ISBN);
    free(manga->anoDaEdicao);
    free(manga->anoFim);
    free(manga->anoInicio);
    free(manga->editora);
    free(manga->genero);
    free(manga->volumesAdquirido);
    free(manga->revista);
    free(manga);
}
void createNewRegitryInDataFile(){
    char final[50];

    FILE *filePointer = fopen(NameDataFile,"a");
    Manga *manga = readFromInput();

    long InitNewRegistryIndex = writeDataFile(manga,filePointer);

    sprintf(final, "%s:%ld|",manga->titulo, InitNewRegistryIndex);

    SeachAndInsertNewPrimaryKeyOrderly(InitNewRegistryIndex,final);

    insertNewDataInSecundaryIndexFile(manga);

    deleteManga(manga);
    fclose(filePointer);
};
