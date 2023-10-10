#include <stdlib.h>
#include "Lista.h"

typedef struct elemento{
    Aluno dado;
    struct elemento *prox;
}Elemento;

Lista* cria_lista(){
    Lista* lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL){
        *lista = NULL;
    }
    return lista;
}

void libera_lista(Lista* lista){
    if(lista != NULL){
        Elemento* no;
        while(*lista != NULL){
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
        }
        free(lista);

    }
}

int tamanho_lista(Lista* lista){
    if(lista == NULL){
        return 0;
    }

    int contador = 0;
    Elemento* no = *lista;

    while(no != NULL){
        contador++;
        no = no->prox;
    }

    return contador;
}

int lista_vazia(Lista* lista){
    if(lista == NULL){
        return 1;
    }
    if(*lista == NULL){
        return 1;
    }
    return 0;
}
