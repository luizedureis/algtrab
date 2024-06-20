#include <stdio.h>
#include <stdlib.h>

#include "mangaDataFileManage.h"
#include "mangaSecundaryIndexManege.h"
#include "readProcess.h"
#include "utils.h"

#define NamePrimaryKeyFile "manga_primary_key_file.txt"

#define EXITCODE 0
void printMenuOptions() {
    printf("Selecione uma opcao:");
    printf("\n   %d. Exit",EXITCODE);
    printf("\n   1. Read");
    printf("\n   2. Create");
    printf("\n   3. Update");
    printf("\n   4. Delete\n");
}

int main(void) {
    int selectInput = -1;
    printMenuOptions();
    scanf("%d",&selectInput);

    while(selectInput!=EXITCODE){
        if(selectInput == 1){
            flush_in();
            runMainReadProcess();
        }
        if (selectInput == 2) {
            flush_in();
            createNewRegitryInDataFile();
        };

        printMenuOptions();
        scanf("%d",&selectInput);
    }


    return 0;
}
