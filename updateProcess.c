//
// Created by Luiz Tavares on 21/06/2024.
//


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "updateProcess.h"
#include "readProcess.h"

#define NameDataFile "manga_data_file.txt"
#define NamePrimaryKeyFile "manga_primary_key_file.txt"

int getIndexInDataFile(){
    Autores autores;
    autores.tam = 0;
    autores.autoresList = malloc(sizeof(MetaAutor));

    getUnicAutoresInList(&autores);
    MetaAutor autorSelecionado = ReadBySecundaryKey(autores);
    char *trabalho_selecionado = readByPrimaryKey(autorSelecionado);
    int indexInDataFile = getMangaIndexFromDataFile(trabalho_selecionado);

    freeAutores(&autores);
    return indexInDataFile;
}
int selectFildToEdit(){
    printf("Selecione o campo que deseja editar:\n");
    printf("    1 ->  INICIO\n");
    printf("    2 ->  FIM\n");
    printf("    3 ->  GENERO\n");
    printf("    4 ->  REVISTA\n");
    printf("    5 ->  EDITORA\n");
    printf("    6 ->  ANO DE EDICAO\n");
    printf("    7 ->  QUANTIDADE DE EDICOES\n");
    printf("    8 ->  EDICOES ADQUIRIDAS\n");
    printf("    8 ->  LISTA DE EDICOES\n");
    int selectInput;
    scanf("%d",&selectInput);
    flush_in();
    return selectInput;
}


void updateFildInDataFile(int indexInDataFile,int indexFildToEdit){
    FILE *mangaDataFilePointer = fopen(NameDataFile,"r+");
    fseek(mangaDataFilePointer,indexInDataFile,SEEK_SET);
    int count=0;
    char character;
    int flagFoundFied=1;
    int inicioFildToEdit,fimFieldToEdit,fimDataFile;
    char *buffer;
    char *valorAtualizado;
    char *valorfinal;
    while((character = fgetc(mangaDataFilePointer)) != EOF){
        if (flagFoundFied==1){
            if(character=='|'){
                if(count<indexFildToEdit+1){
                    count++;
                }else{
                    flagFoundFied=0;
                    inicioFildToEdit= ftell(mangaDataFilePointer);
                }
            }
        }else{
//            vamos localizar onde esta o final desse cara
            if (character=='|'){
                fimFieldToEdit = ftell(mangaDataFilePointer);
//              vamos salvar no buffer os valores que estao dps do fild que vai ser alterado
                fseek(mangaDataFilePointer,0,SEEK_END);
                fimDataFile=ftell(mangaDataFilePointer);
                fseek(mangaDataFilePointer,fimFieldToEdit,SEEK_SET);

                buffer = (char *)malloc(fimDataFile);
                int numElements = fimDataFile-fimFieldToEdit-1;
                fread(buffer, sizeof(char), numElements, mangaDataFilePointer);
                buffer[numElements] = '\0';

//              vamos pegar o q tem que ser salvo
                printf("Escreva oq vc quer salvar: ");
                valorAtualizado = readStringFromInput();
                valorfinal = (char*) malloc(sizeof(valorAtualizado)+sizeof(char*));
                sprintf(valorfinal, "%s|",(valorAtualizado));
//                 voltar para o comeco do field que vai alterado e inserimos o novo valor
                fseek(mangaDataFilePointer,inicioFildToEdit,SEEK_SET);

                fputs(valorfinal, mangaDataFilePointer);
                printf("buffer -> %s\n",buffer);
                fseek(mangaDataFilePointer,inicioFildToEdit+ (long)strlen(valorfinal),SEEK_SET);
                fprintf(mangaDataFilePointer,"%s",buffer);
                break;
            }
        }

    }
    free(valorfinal);
    free(buffer);
    free(valorAtualizado);
    fclose(mangaDataFilePointer);
}

void updateDataFile() {
    int indexInDataFile = getIndexInDataFile();
    int fieldToEdit = selectFildToEdit();
    updateFildInDataFile(indexInDataFile, fieldToEdit);
};

int searchForTitleInDataFile(char *title){
    FILE *dataFilePointer = fopen(NameDataFile,"r+");
    int inicio =0;
    int fim =0;
    int flagFim=1;
    int iniciobackup =0;
    char character;
    char buffer[50];
    int count = 0;
    while((character = fgetc(dataFilePointer)) != EOF) {
        if (character=='|'){
            if(flagFim==1){
                fim = ftell(dataFilePointer);
                flagFim=0;
            }else{
                inicio = ftell(dataFilePointer);
                flagFim=1;
                if(count==1){
                    int numElementos = inicio-fim-1;
                    fseek(dataFilePointer,fim,SEEK_SET);
                    fread(buffer, sizeof(char), numElementos, dataFilePointer);
                    buffer[numElementos]='\0';
                    fseek(dataFilePointer,inicio,SEEK_SET);
                    if(strcmp(buffer, title)==0) return iniciobackup;
                }
            }
            count++;
        }
        if(character=='#') {
            count = 0;
            iniciobackup = ftell(dataFilePointer);
        }
    }

}

int updateIndexFile(){
    FILE *primaryIndexFilePointer = fopen(NamePrimaryKeyFile,"r+");
    char character;
    int inicio = 0;
    int fim = 0;
    int fimArquivo = 0;
    int numElements;
    char buffer[50];
    char bufferIndex[50];
    int indexAtualizado;
    fseek(primaryIndexFilePointer,0,SEEK_END);
    fimArquivo = ftell(primaryIndexFilePointer);
    fseek(primaryIndexFilePointer,0,SEEK_SET);


    while((character = fgetc(primaryIndexFilePointer)) != EOF) {
        if(character==':'){
            fim = ftell(primaryIndexFilePointer);
            numElements = fim-inicio-1;
            fseek(primaryIndexFilePointer,inicio,SEEK_SET);
            fread(buffer, sizeof(char), numElements, primaryIndexFilePointer);
            fseek(primaryIndexFilePointer,fim,SEEK_SET);
            buffer[numElements]='\0';
            indexAtualizado = searchForTitleInDataFile(buffer);
            printf("procurando por %s -> %d\n",buffer, indexAtualizado);

            if (indexAtualizado==-1) return 1;
        }
        if(character=='|'){
            inicio = ftell(primaryIndexFilePointer);
            numElements = inicio-fim-1;
            fseek(primaryIndexFilePointer,fim,SEEK_SET);
            fread(bufferIndex, sizeof(char), numElements, primaryIndexFilePointer);
            fseek(primaryIndexFilePointer,inicio,SEEK_SET);
            bufferIndex[numElements]='\0';
            if(atoi(bufferIndex)!=indexAtualizado){
                char *bufferIndexFile = (char*)malloc(sizeof(fimArquivo)+sizeof(char*));
                fread(bufferIndexFile, sizeof(char), fimArquivo-inicio-1, primaryIndexFilePointer);
                bufferIndexFile[fimArquivo-inicio-1]='\0';
                fseek(primaryIndexFilePointer,fim ,SEEK_SET);
                fprintf(primaryIndexFilePointer,"%d|",indexAtualizado);
                fprintf(primaryIndexFilePointer,"%s",bufferIndexFile);
                free(bufferIndexFile);
            }
        }
    }
    return 0;
}
int updateMainProcess(){
    updateDataFile();
    updateIndexFile();
    return 0;
}