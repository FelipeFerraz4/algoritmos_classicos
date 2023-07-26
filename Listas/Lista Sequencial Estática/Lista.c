#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct list{
    int size_element;
    struct student data[SIZE_LIST];
    /*
    struct data{
        struct student[SIZE_LIST];
    }
    */
};

List* create_list(){
    List* list;
    list = (List*) malloc(sizeof(struct list));
    if(list != NULL){
        list->size_element = 0;
    }
    return list;
}

void free_list(List* list){
    free(list);
}

int size_list(List* list){
    if(list == NULL){
        return -1;
    }
    else{
        return list->size_element;
    }
}

int full_list(List* list){
    if(list == NULL){
        return -1;
    }
    else{
        return (list->size_element == SIZE_LIST);
    }
}

int empty_list(List* list){
    if(list == NULL){
        return -1;
    }
    else{
        return (list->size_element == 0);
    }
}

//adiciona elementos no final da lista
int add_list_element(List* list, Student student){
    if(list == NULL){
        return 0;
    }
    
    if(full_list(list) == 1){
        return 0;
    }
    
    list->data[list->size_element] = student;
    list->size_element++;
    return 1;
}

//adiciona elementos no inicio da lista
int add_beginning_list(List* list, Student student){
    if(list == NULL){
        return 0;
    }
    
    if(full_list(list)  == 1){
        return 0;
    }
    
    for(int i = list->size_element - 1; i >= 0; i--){
        list->data[i+1] = list->data[i];
    }
    
    list->data[0] = student;
    list->size_element++;
    return 1;
}

//adiciona elemento de forma ordenada na lista
int add_sort_list(List* list, Student student){
    if(list == NULL){
        return 0;
    }
    
    if(full_list(list)  == 1){
        return 0;
    }
    
    int i = 0;
    while(i < list->size_element && list->data[i].ID < student.ID){
        i++;
    }
    
    for(int j = list->size_element - 1; j >= i; j--){
        list->data[j+1] = list->data[j];
    }
    
    list->data[i] = student;
    list->size_element++;
    return 1;
}
