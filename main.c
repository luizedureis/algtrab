#include <stdio.h>
#include <stdlib.h>

#include "mangaDataFileManage.h"
#include "mangaSecundaryIndexManege.h"
#include "readProcess.h"
#include "deleteProcess.h"
#include "utils.h"
#include "updateProcess.h"
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
        }else if (selectInput == 2) {
            flush_in();
            createNewRegitryInDataFile();
        }else if(selectInput==3){
            flush_in();
            updateMainProcess();
        }else if(selectInput == 4){
            flush_in();
            removeMainProcess();
        }else{
            printf("Insira um valor válido\n");
        }


        printMenuOptions();
        scanf("%d",&selectInput);
    }


    return 0;
}
