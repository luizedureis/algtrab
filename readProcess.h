//
// Created by Luiz Tavares on 19/06/2024.
//

#ifndef ALG_INDEX_READPROCESS_H
#define ALG_INDEX_READPROCESS_H
typedef struct _metaAutor{
    int tamanho;
    char *autor;
    char **lista_trabalhos;
    int capacity;
}MetaAutor;
typedef struct _autores{
    int tam;
    MetaAutor *autoresList;
}Autores;


void runMainReadProcess();
void getUnicAutoresInList(Autores *autores);
MetaAutor ReadBySecundaryKey(Autores autores);
char *readByPrimaryKey(MetaAutor autorSelecionado);
int getMangaIndexFromDataFile(char *nomelivro);
void printDataFromMangaOutput(int index);
void freeAutores(Autores *autores) ;


#endif //ALG_INDEX_READPROCESS_H
