#include <stdlib.h>
#include <time.h>
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
    Dados aux;
    pai = (filho - 1) / 2;
    while(filho > 0  && fila_de_naves->dados[pai].prioridade
           <= fila_de_naves->dados[filho].prioridade){
        aux = fila_de_naves->dados[filho];
        fila_de_naves->dados[filho] = fila_de_naves->dados[pai];
        fila_de_naves->dados[pai] = aux;

        filho = pai;
        pai = (filho - 1) /2;
    }
}

int inserir_heap(Heap* fila_de_naves, Nave nave, int prioridade){
    if(fila_de_naves == NULL){
        return 0;
    }
    if(fila_de_naves->quantidade_nave == DEFAULT_MAX){
        return 0;
    }

    fila_de_naves->dados[fila_de_naves->quantidade_nave].nave =  nave;
    fila_de_naves->dados[fila_de_naves->quantidade_nave].prioridade = prioridade;

    subir_heap(fila_de_naves, fila_de_naves->quantidade_nave);

    fila_de_naves->quantidade_nave++;
    return 1;
}

void descer_heap(Heap* fila_de_naves, int pai){
    Dados aux;
    int filho = (2 * pai) + 1;
    while(filho < fila_de_naves->quantidade_nave){
        if(filho < fila_de_naves->quantidade_nave - 1){
            if(fila_de_naves->dados[filho].prioridade <
               fila_de_naves->dados[filho+1].prioridade){
                filho++;
            }
        }

        if(fila_de_naves->dados[pai].prioridade >=
           fila_de_naves->dados[filho].prioridade){
            break;
        }

        aux = fila_de_naves->dados[pai];
        fila_de_naves->dados[pai] = fila_de_naves->dados[filho];
        fila_de_naves->dados[filho] = aux;

        pai = filho;
        filho = (2 * pai) + 1;
    }
}

int remove_heap(Heap* fila_de_naves){
    if(fila_de_naves == NULL){
        return 0;
    }
    if(fila_de_naves->quantidade_nave == 0){
        return 0;
    }

    fila_de_naves->quantidade_nave--;
    fila_de_naves->dados[0] = fila_de_naves->dados[fila_de_naves->quantidade_nave];
    descer_heap(fila_de_naves, 0);
    return 1;
}

int verifica_prioridade(int prioridade){
    int valido = (rand() % 10);

    if(valido == 0){
        int ajuste = (rand() % 10);
        if(0 <= ajuste && ajuste < 6){
            prioridade = prioridade * ( -(rand() % 10) );
        }else{
            prioridade = prioridade * (rand() % 10);
        }
    }

    return prioridade;
}

