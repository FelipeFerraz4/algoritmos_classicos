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

int removeElement(SequentialList* list_int, int position){
    if (list_int == NULL ){
        return 0;
    }

    if (position < 0 || position >= list_int->size_list){
        return 0;
    }

    for(int i = position; i < list_int->size_list - 1; i++){
        list_int->list_int[i] = list_int->list_int[i+1];
    }

    list_int->size_list--;
    return 1;
}

int searchElement(SequentialList* list_int, int element){
    if (list_int == NULL){
        return -1;
    }

    if (list_int->size_list == 0){
        return -1;
    }

    int i = 0;
    while(i < list_int->size_list &&
          list_int->list_int[i] != element){
        i++;
    }

    if (i == list_int->size_list){
        return 0;
    }

    return i;
}
