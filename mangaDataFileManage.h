//
// Created by Luiz Tavares on 11/06/24.
//

#ifndef ALG_INDEX_MANGADATAFILEMANAGE_H
#define ALG_INDEX_MANGADATAFILEMANAGE_H
#include <stdio.h>

typedef struct manga_t{
    char *ISBN;
    char *titulo;
    char *autores;
    char *anoInicio;
    char *anoFim;
    char *genero;
    char *revista;
    char *editora;
    char *anoDaEdicao;
    int qntVolumes;
    int qntVolumesAdquiridos;
    char *volumesAdquirido;
}Manga;

Manga* readFromInput();
void createNewRegitryInDataFile();
long writeDataFile(Manga *manga,FILE *filePointer);

#endif //ALG_INDEX_MANGADATAFILEMANAGE_H
