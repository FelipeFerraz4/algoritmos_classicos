#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/*
struct list_student{
    int size_element;
    Student data[SIZE_LIST];
};
*/

List* create_list(){
    List* list_student;
    list_student = (List*) malloc(sizeof(struct list_student));
    if(list_student != NULL){
        list_student->size_element = 0;
    }
    return list_student;
}

void free_list(List* list_student){
    free(list_student);
}

int size_list(List* list_student){
    if(list_student == NULL){
        return -1;
    }
    else{
        return list_student->size_element;
    }
}

int full_list(List* list_student){
    if(list_student == NULL){
        return -1;
    }
    else{
        return (list_student->size_element == SIZE_LIST);
    }
}

int empty_list(List* list_student){
    if(list_student == NULL){
        return -1;
    }
    else{
        return (list_student->size_element == 0);
    }
}

//adiciona elementos no final da lista
int add_end_list_element(List* list_student, Student student){
    if(list_student == NULL){
        return 0;
    }

    if(full_list(list_student) == 1){
        return 0;
    }

    list_student->data[list_student->size_element] = student;
    list_student->size_element++;
    return 1;
}

//adiciona elementos no inicio da lista
int add_beginning_list(List* list_student, Student student){
    if(list_student == NULL){
        return 0;
    }

    if(full_list(list_student)  == 1){
        return 0;
    }

    for(int i = list_student->size_element - 1; i >= 0; i--){
        list_student->data[i+1] = list_student->data[i];
    }

    list_student->data[0] = student;
    list_student->size_element++;
    return 1;
}

//adiciona elemento de forma ordenada na lista
int add_sort_list(List* list_student, Student student){
    if(list_student == NULL){
        return 0;
    }

    if(full_list(list_student)  == 1){
        return 0;
    }

    int i = 0;
    while(i < list_student->size_element && list_student->data[i].ID < student.ID){
        i++;
    }

    for(int j = list_student->size_element - 1; j >= i; j--){
        list_student->data[j+1] = list_student->data[j];
    }

    list_student->data[i] = student;
    list_student->size_element++;
    return 1;
}

int remove_end_list(List* list_student){
    if(list_student == NULL){
        return 0;
    }

    if(list_student->size_element == 0){
        return 0;
    }

    list_student->size_element--;
    return 1;
}

int remove_beginning_list(List* list_student){
    if(list_student == NULL){
        return 0;
    }

    if(list_student->size_element == 0){
        return 0;
    }

    for(int i = 0; i < list_student->size_element - 1; i++){
        list_student->data[i] = list_student->data[i+1];
    }

    list_student->size_element--;
    return 1;
}

int remove_list(List* list_student, int key){
    if(list_student == NULL){
        return 0;
    }

    if(list_student->size_element == 0){
        return 0;
    }

    int i = 0;
    while(i < list_student->size_element && list_student->data[i].ID != key){
        i++;
    }

    if(i == list_student->size_element){
        return 0;
    }

    for(int j = i; i < list_student->size_element-1; j++){
        list_student->data[j] = list_student->data[j+1];
    }

    list_student->size_element--;
    return 1;
}

int search_position_list(List* list_student, int position, Student* student){
    if(list_student == 0){
        return 0;
    }

    if(position <= 0 || position > list_student->size_element){
        return 0;
    }

    *student = list_student->data[position-1];
    return 1;
}


int search_key_list(List* list_student, int key, Student* student){
    if(list_student == NULL){
        return 0;
    }

    int i = 0;
    while(i < list_student->size_element && list_student->data[i].ID != key){
        i++;
    }

    if(i == list_student->size_element){
        return 0;
    }

    *student = list_student->data[i];
    return 1;
}

