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
