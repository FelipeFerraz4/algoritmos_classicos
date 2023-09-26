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

int inserir_inicio(Lista* lista, Aluno novoAluno){
    if(lista == NULL){
        return 0;
    }

    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    no->dado = novoAluno;
    no->prox = (*lista);

    *lista = no;

    return 1;
}

int inserir_fim(Lista* lista, Aluno novoAluno){
    if(lista == NULL){
        return 0;
    }

    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    no->dado = novoAluno;
    no->prox = NULL;

    if(*lista == NULL){
        *lista = no;
    }
    else{
        Elemento* aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int inserir_ordenado(Lista* lista, Aluno novoAluno){
    if(lista == NULL){
        return 0;
    }

    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    no->dado = novoAluno;

    if(lista_vazia(lista) == 1){
        no->prox = *lista;
        *lista = no;
    }
    else{
        Elemento *anterior, *atual = *lista;

        while(atual != NULL && atual->dado.id < novoAluno.id){
            anterior = atual;
            atual = atual->prox;
        }

        if(atual == *lista){
            no->prox = *lista;
            *lista = no;
        }
        else{
            no->prox = anterior->prox;
            anterior->prox = no;
        }
    }
    return 1;
}
