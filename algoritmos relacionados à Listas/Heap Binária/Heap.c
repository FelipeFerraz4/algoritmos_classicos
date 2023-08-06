#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

Heap* create_heap(){

    Heap *heap = (Heap*) malloc(sizeof(Heap));

    if(heap != NULL){
        heap->size_heap = 0;
        heap->root = NULL;
    }

    return heap;

}

void free_no(No *root){
    if(root != NULL){
        if(root->right_child != NULL){
            free_no(root->right_child);
        }
        if(root->left_child != NULL){
            free_no(root->left_child);
        }
        free(root);
    }
}

void free_heap(Heap *heap){
    if(heap != NULL){
        if(heap->root != NULL){
            free_no(heap->root);
       }
        free(heap);
    }
}
