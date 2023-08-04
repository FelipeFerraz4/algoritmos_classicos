#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


List* create_list(){

    List* list_student = (List*) malloc(sizeof(List));

    if(list_student != NULL){
        *list_student = NULL;
    }

    return list_student;
}

void free_list(List* list_student){
    if(list_student != NULL){
        No* no;
        while(*list_student != NULL){
            no = *list_student;
            *list_student = (*list_student)->next;
            free(no);
        }
        free(list_student);
    }
}
