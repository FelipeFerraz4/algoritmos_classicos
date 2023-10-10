#include <stdlib.h>
#include "heap.h"

Heap* criar_heap(){
    Heap *fila_de_naves;
    fila_de_naves = (Heap*) malloc(sizeof(Heap));
    if(fila_de_naves != NULL){
        fila_de_naves->quantidade_nave = 0;
    }
    return fila_de_naves;
}

void libera_heap(Heap* fila_de_naves){
    free(fila_de_naves);
}

int tamanho_heap(Heap* fila_de_naves){
    if(fila_de_naves == NULL){
        return -1;
    }
    return fila_de_naves->quantidade_nave;
}

int heap_cheio(Heap* fila_de_naves){
    if(fila_de_naves == NULL){
        return -1;
    }
    if(fila_de_naves->quantidade_nave == DEFAULT_MAX){
        return 1;
    }
    return 0;
}

int heap_vazio(Heap* fila_de_naves){
    if(fila_de_naves == NULL){
        return -1;
    }
    if(fila_de_naves->quantidade_nave == 0){
        return 1;
    }
    return 0;
}

void subir_heap(Heap* fila_de_naves, int filho){
    int pai;
    Nave aux;
    pai = (filho - 1) / 2;
    while(filho > 0  && fila_de_naves->naves[pai].prioridade
           <= fila_de_naves->naves[filho].prioridade){
        aux = fila_de_naves->naves[filho];
        fila_de_naves->naves[filho] = fila_de_naves->naves[pai];
        fila_de_naves->naves[pai] = aux;

        filho = pai;
        pai = (filho - 1) /2;
    }
}

int inserir_heap(Heap* fila_de_naves, Dados dados, int prioridade){
    if(fila_de_naves == NULL){
        return 0;
    }
    if(fila_de_naves->quantidade_nave == DEFAULT_MAX){
        return 0;
    }

    fila_de_naves->naves[fila_de_naves->quantidade_nave].dados =  dados;
    fila_de_naves->naves[fila_de_naves->quantidade_nave].prioridade = prioridade;

    subir_heap(fila_de_naves, fila_de_naves->quantidade_nave);

    fila_de_naves->quantidade_nave++;
    return 1;
}


