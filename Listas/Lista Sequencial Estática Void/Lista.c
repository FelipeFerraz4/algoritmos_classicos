#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"


List* create_list(int SIZE_TYPE){
    List* generic_list;
    generic_list = (List*) malloc(sizeof(List*));
    if(generic_list != NULL){
        generic_list->size_list = 0;
        generic_list->SIZE_TYPE = SIZE_TYPE;
    }
    return generic_list;
}

void free_list(List* generic_list){
    for(int i = 0; i < generic_list->size_list; i++){
        free(generic_list->element[i].data);
    }
    free(generic_list);
}

int add_sort_list(List* generic_list, int key, void* element){
    if(generic_list == NULL){
        return 0;
    }

    if(generic_list->size_list == MAX_SIZE_LIST){
        return 0;
    }

    void* new_element = malloc(generic_list->SIZE_TYPE);
    if(new_element == NULL){
        return 0;
    }

    //copia as informações do element para new_element que
    //tem o tamanho SIZE_TYPE
    memcpy(new_element, element, generic_list->SIZE_TYPE);

    int i = 0;
    while(i < generic_list->size_list && generic_list->element[i].key < key){
        i++;
    }

    for(int j = generic_list->size_list-1; j >= i; j--){
        generic_list->element[j+1] = generic_list->element[j];
    }

    generic_list->element[i].key = key;
    generic_list->element[i].data = new_element;

    generic_list->size_list++;
    return 1;
}

int remove_list(List* generic_list, int key){
    if(generic_list == NULL){
        return 0;
    }

    if(generic_list->size_list == 0){
        return 0;
    }

    int i = 0;
    while(i < generic_list->size_list && generic_list->element[i].key != key){
        i++;
    }

    if(i == generic_list->size_list){
        return 0;
    }

    free(generic_list->element[i].data);

    for(int j = i; j < generic_list->size_list; j++){
        generic_list->element[j] = generic_list->element[j+1];
    }

    generic_list->size_list--;
    return 1;
}

