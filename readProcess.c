#include "readProcess.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NameSecundaryKeyFile "manga_secundary_key_file.txt"
#define NamePrimaryKeyFile "manga_primary_key_file.txt"
#define NameDataFile "manga_data_file.txt"

MetaAutor ReadBySecundaryKey(Autores autores){
    printf("Selecione um Autor: \n");
    for (int i = 0; i < autores.tam; i++) {
        printf("    %d -> %s\n", i,autores.autoresList[i].autor);
    }
    int selectInput;
    scanf("%d",&selectInput);
    flush_in();
    return autores.autoresList[selectInput];
}

int checkIfAutorAlreadyExistInList(Autores autores, const char *name){
    for (int i = 0; i < autores.tam; i++) {
        if(strcmp(autores.autoresList[i].autor, name) == 0) {
            return 1;
        }
    }
    return 0;
}

void insertBookInAutor(Autores **autores,char *titulo,char *autor){
    for (int i=0; i<(*autores)->tam;i++){
        if (strcmp((*autores)->autoresList[i].autor,autor)==0){
            int tam = (*autores)->autoresList[i].tamanho;
            (*autores)->autoresList[i].lista_trabalhos = realloc((*autores)->autoresList[i].lista_trabalhos,sizeof((*autores)->autoresList[i].lista_trabalhos)*sizeof(titulo));
            (*autores)->autoresList[i].lista_trabalhos[tam] = (char*) malloc(sizeof(titulo)+1);
            strcpy((*autores)->autoresList[i].lista_trabalhos[tam], titulo);
            (*autores)->autoresList[i].tamanho++;

//            (*autores)->autoresList[i].lista_trabalhos[tam] = (char*) malloc((strlen(titulo) + 1) * sizeof(char));
        }

    }

}
//            (*autores)->autoresList[i].lista_trabalhos[tam - 1] = (char) malloc((strlen(titulo) + 1) * sizeof(char));
void getUnicAutoresInList(Autores *autores){
    FILE *filePointer = fopen(NameSecundaryKeyFile, "r+");
    if (filePointer == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char character;
    char buffer[50];
    int inicio = 0;
    int fim = 0;
        while ((character = fgetc(filePointer)) != EOF) {
            if(character == ':'){
                fim = ftell(filePointer);
                int numelements = fim - inicio - 1;
                fseek(filePointer, inicio, SEEK_SET);
                fread(buffer, sizeof(char), numelements, filePointer);  // Lê os dados para o buffer
                buffer[numelements] = '\0';
                fseek(filePointer, fim, SEEK_SET);
                if(!checkIfAutorAlreadyExistInList(*autores, buffer)){
                    autores->tam++;
                    // Realoca a memória para o array de ponteiros de strings
                    autores->autoresList = realloc(autores->autoresList, autores->tam * sizeof(MetaAutor));

                    // Aloca memória para a nova string e copia o nome do autor para o array
                    autores->autoresList[autores->tam - 1].autor = malloc((strlen(buffer) + 1) * sizeof(char));
                    strcpy(autores->autoresList[autores->tam - 1].autor, buffer);
                    autores->autoresList[autores->tam - 1].tamanho=0;
                    autores->autoresList[autores->tam - 1].lista_trabalhos= malloc(sizeof(char));;
                }
            }
            if(character == '|'){
                char buffer2[50];
                inicio = ftell(filePointer);
                fseek(filePointer, fim, SEEK_SET);
                int numelements = inicio - fim - 1;
                fread(buffer2, sizeof(char), numelements, filePointer);  // Lê os dados para o buffer
                buffer2[numelements] = '\0';
                fseek(filePointer, inicio, SEEK_SET);
                insertBookInAutor(&autores,buffer2,buffer);
            }
        }
    fclose(filePointer);
}
char *readByPrimaryKey(MetaAutor autorSelecionado){
    printf("Esses sao os trabalhos disponiveis, escolha um: \n");
    for (int i=0;i<autorSelecionado.tamanho;i++){
        printf("%d -> Livro %s\n",i,autorSelecionado.lista_trabalhos[i]);
    }
    int selectInput;
    scanf("%d",&selectInput);
    flush_in();
    return &autorSelecionado.lista_trabalhos[selectInput];
}
int getMangaIndexFromDataFile(char *nomelivro){
    FILE *primaryKeyFilePointer = fopen(NamePrimaryKeyFile, "r+");
    char character;
    int inicio,fim;

    char bufferTitulo[50];
    char bufferIndexInDataFile[50];

    inicio = fim = 0;
    while((character = fgetc(primaryKeyFilePointer)) != EOF){
        if(character==':'){
            fim = ftell(primaryKeyFilePointer);
            int numElementos = fim-inicio-1;
            fseek(primaryKeyFilePointer,inicio,SEEK_SET);
            fread(bufferTitulo, sizeof(char), numElementos, primaryKeyFilePointer);  // Lê os dados para o buffer
            bufferTitulo[numElementos] = '\0';
            fseek(primaryKeyFilePointer,fim,SEEK_SET);
        }
        if(character=='|'){
            inicio = ftell(primaryKeyFilePointer);
            int numElementos = inicio-fim-1;
            fseek(primaryKeyFilePointer,fim,SEEK_SET);
            fread(bufferIndexInDataFile,sizeof(char),numElementos,primaryKeyFilePointer);
            bufferIndexInDataFile[numElementos]='\0';
            fseek(primaryKeyFilePointer,inicio,SEEK_SET);
            if(strcmp(bufferTitulo,nomelivro)==0){
                return atoi(bufferTitulo);
            }
        }

    }
}
void printDataFromMangaOutput(int index){
    FILE *mangaDataFilePointer = fopen(NameDataFile,"r+");
    fseek(mangaDataFilePointer,index,SEEK_SET);
    char character;
    char *buffer;
    int inicio=index;
    int fim = index;
    int flagFim;
    flagFim=0;
    while((character = fgetc(mangaDataFilePointer))!=EOF){
        if(character=='|'){
            fim = ftell(mangaDataFilePointer);
            char buffer[50];
            int numElements = fim-inicio-1;
            fseek(mangaDataFilePointer,inicio,SEEK_SET);
            fread(buffer, sizeof(char),numElements,mangaDataFilePointer);
            fseek(mangaDataFilePointer,fim,SEEK_SET);
            buffer[numElements]='\0';
            printf("%s\n",buffer);
            flagFim=1;
        }
        if(flagFim!=0){
            inicio = fim;
            flagFim=0;
        }
        if (character=='#'){
            break;
        }
    }
}
void freeAutores(Autores *autores) {
    if (autores != NULL) {
        for (int i = 0; i < autores->tam; i++) {
            free(autores->autoresList[i].autor);
            for(int j=0;j<autores->autoresList[i].tamanho;j++){
                free(autores->autoresList[i].lista_trabalhos[j]);
            }
            free(autores->autoresList[i].lista_trabalhos);
        }
        // Libere o array autoresList
        free(autores->autoresList);
    }
}

void runMainReadProcess() {
    // vamos acessar o arquivo de indice secundario e puxar todos os autores
    // para um programa muito grande isso nunca seria uma opção
    Autores autores;
    autores.tam = 0;
    autores.autoresList = malloc(sizeof(MetaAutor));

    getUnicAutoresInList(&autores);
    MetaAutor autorSelecionado;
    autorSelecionado = ReadBySecundaryKey(autores);
    char *trabalho_selecionado = readByPrimaryKey(autorSelecionado);
    printDataFromMangaOutput(getMangaIndexFromDataFile(trabalho_selecionado));
    // Libera a memória alocada
    freeAutores(&autores);
}
