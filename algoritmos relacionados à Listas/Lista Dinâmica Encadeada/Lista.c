#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


List* create_list(){

    List* student_list = (List*) malloc(sizeof(List));

    if(student_list != NULL){
        *student_list = NULL;
    }

    return student_list;
}

void free_list(List* student_list){
    if(student_list != NULL){
        No* no;
        while(*student_list != NULL){
            no = *student_list;
            *student_list = (*student_list)->next;
            free(no);
        }
        free(student_list);
    }
}

int size_list(List* student_list){
    if(student_list == NULL){
        return 0;
    }

    int count = 0;
    No* no = *student_list;
    while(no != NULL){
        count++;
        no = no->next;
    }
    return count;
}

int empty_list(List* student_list){
    if(student_list == NULL){
        return 1;
    }

    if(*student_list == NULL){
        return 1;
    }

    return 0;
}
