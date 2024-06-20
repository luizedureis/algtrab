//
// Created by Luiz Tavares on 12/06/24.
//

#include <stdio.h>

#ifndef ALG_INDEX_MANGAPRIMARYINDEXMANEGE_H
#define ALG_INDEX_MANGAPRIMARYINDEXMANEGE_H
void moveDataAndInsertNewDataInPrimaryDataFile(FILE *filePointer,long indexToInsert,char *stringToInsert);
void SeachAndInsertNewPrimaryKeyOrderly(long indexInDataFile,char* primarykey);


#endif //ALG_INDEX_MANGAPRIMARYINDEXMANEGE_H
