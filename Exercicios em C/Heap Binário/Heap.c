#include <stdlib.h>
#include <string.h>
#include "Heap.h"

Heap* create_heap(){
    Heap* heap;
    heap = (Heap*) malloc(sizeof(Heap));
    if (heap != NULL){
        heap->size_heap = 0;
    }
    return heap;
}

void free_heap(Heap* heap){
    free(heap);
}

int empty_heap(Heap* heap){
    if (heap == NULL){
        return 0;
    }

    if (heap->size_heap == 0){
        return 1;
    }

    return 0;
}

int full_heap(Heap* heap){
    if(heap == NULL){
        return 0;
    }

    if(heap->size_heap == MAX_SIZE_HEAP){
        return 1;
    }

    return 0;

}

void promote_element(Heap* heap, int children) {
    int father;
    Aluno aux;

    father = (children -1) /2;

    while(children > 0 && heap->alunos[father].priority
           <= heap->alunos[children].priority){

        aux = heap->alunos[children];

        heap->alunos[children] = heap->alunos[father];

        heap->alunos[father] = aux;

        children = father;
        father = (father - 1) / 2;
    }
}

int insert_heap(Heap* heap, char* name, int priority){
    if (heap == NULL){
        return 0;
    }

    if (heap->size_heap == MAX_SIZE_HEAP){
        return 0;
    }

    strcpy(heap->alunos[heap->size_heap].name, name);
    heap->alunos[heap->size_heap].priority = priority;

    promote_element(heap, heap->size_heap);

    heap->size_heap++;
    return 1;
}

void demote_element(Heap* heap, int father){
    Aluno aux;
    int children = (2 * father) + 1;

    while(children < heap->size_heap) {
        if(children < heap->size_heap-1){
            if(heap->alunos[children].priority <
               heap->alunos[children+1].priority){
                children++;
               }
        }

        if(heap->alunos[father].priority >=
           heap->alunos[children].priority){
            break;
        }

        aux = heap->alunos[father];
        heap->alunos[father] = heap->alunos[children];
        heap->alunos[children] = aux;

        father = children;
        children = (2 * father) + 1;
    }
}

int remove_heap(Heap* heap){
    if(heap == NULL){
        return 0;
    }

    if(heap->size_heap == 0){
        return 0;
    }

    heap->size_heap--;
    heap->alunos[0] = heap->alunos[heap->size_heap];
    demote_element(heap, 0);
    return 1;
}

int search_heap(Heap* heap, char* name){
    if (heap == NULL || heap->size_heap == 0){
        return 0;
    }

    strcpy(name, heap->alunos[0].name);
    return 1;
}
