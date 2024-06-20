//
// Created by Luiz Tavares on 13/06/24.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef ALG_INDEX_MANGASECUNDARYINDEXMANEGE_H
#define ALG_INDEX_MANGASECUNDARYINDEXMANEGE_H

long checkIfSecundaryKeyAlreadyExist(FILE *filePointer,char *autor);
int insertNewDataInSecundaryIndexFile(Manga *manga);
void moveDataAndInsertNewDataInSecundaryDataFile(FILE *filePointer,long indexToInsert,char *stringToInsert);

#endif //ALG_INDEX_MANGASECUNDARYINDEXMANEGE_H
