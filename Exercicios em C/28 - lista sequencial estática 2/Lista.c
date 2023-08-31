#include "Lista.h"
#include <stdlib.h>

SequentialList* create_list(){
    SequentialList* sequentialList;
    sequentialList = (SequentialList*) malloc(sizeof(SequentialList));
    if (sequentialList != NULL){
        sequentialList->size_list = 0;
    }
    return sequentialList;
}

void free_list(SequentialList* list_int){
    free(list_int);
}

int insertElement(SequentialList* list_int, int data){
    if (list_int == NULL){
        return 0;
    }

    if (list_int->size_list == MAX_SIZE_LIST){
        return 0;
    }

    list_int->list_int[list_int->size_list] = data;

    list_int->list_int[list_int->size_list] = data;
    list_int->size_list++;
    return 1;
}
