#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


List* create_list(){

    List *student_list = (List*) malloc(sizeof(List));

    if(student_list != NULL){
        *student_list = NULL;
    }

    return student_list;
}

void free_list(List *student_list){
    if(student_list != NULL){
        No *no;
        while(*student_list != NULL){
            no = *student_list;
            *student_list = (*student_list)->next;
            free(no);
        }
        free(student_list);
    }
}

int size_list(List *student_list){
    if(student_list == NULL){
        return 0;
    }

    int count = 0;
    No *no = *student_list;
    while(no != NULL){
        count++;
        no = no->next;
    }
    return count;
}

int empty_list(List *student_list){
    if(student_list == NULL){
        return 1;
    }

    if(*student_list == NULL){
        return 1;
    }

    return 0;
}

int add_beginnig(List *student_list, Student new_student){
    if(student_list == NULL){
        return 0;
    }

    No *no = (No*) malloc(sizeof(No));

    if(no == NULL){
        return 0;
    }

    no->data = new_student;
    no->next = (*student_list);

    *student_list = no;

    return 1;
}

int add_end(List *student_list, Student new_student){
    if(student_list == NULL){
        return 0;
    }

    No *no = (No*) malloc(sizeof(No));

    if(no == NULL){
        return 0;
    }

    no->data = new_student;
    no->next = NULL;

    if((*student_list) == NULL){
        *student_list = no;
    }
    else{
        No* aux = *student_list;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = no;
    }

    return 1;
}

int add_sort(List *student_list, Student new_student){
    if(student_list == NULL){
        return 0;
    }

    No* no = (No*) malloc(sizeof(No));

    if(no == NULL){
        return 0;
    }

    no->data = new_student;

    if(empty_list(student_list) == 1){
        no->next = (*student_list);
        *student_list = no;
        return 1;
    }
    else{
        No *previous, *current = *student_list;

        while(current != NULL && current->data.id < new_student.id){
            previous = current;
            current = current->next;
        }

        if(current == *student_list){
            no->next = (*student_list);
            *student_list = no;
        }
        else{
            no->next = previous->next;
            previous->next = no;
        }
        return 1;
    }
}

int remove_beginning(List* student_list){
    if(student_list == NULL){
        return 0;
    }

    if((*student_list) == NULL){
        return 0;
    }

    No *no = *student_list;

    *student_list = no->next;

    free(no);

    return 1;
}

int remove_end(List* student_list){
    if(student_list == NULL){
        return 0;
    }

    if((*student_list) == NULL){
        return 0;
    }

    No *previous, *no = *student_list;
    while(no->next != NULL){
        previous = no;
        no = no->next;
    }

    if(no == (*student_list)){
        *student_list = no->next;
    }
    else{
        previous->next = no->next;
    }

    free(no);
    return 1;
}

int remove_list(List* student_list, int key){
    if(student_list == NULL){
        return 0;
    }

    No *previous, *no = *student_list;
    while(no != NULL && no->data.id != key){
        previous = no;
        no = no->next;
    }

    if(no == NULL){
        return 0;
    }

    if(no == *student_list){
        *student_list = no->next;
    }
    else{
        previous->next = no->next;
    }

    free(no);
    return 1;
}

int search_position(List* student_list, int position, Student *student){
    if(student_list == NULL || position <= 0){
        return 0;
    }

    No *no = *student_list;
    int i = 1;

    while(no != NULL && i < position){
        no = no->next;
        i++;
    }

    if(no == NULL){
        return 0;
    }
    else{
        *student = no->data;
        return 1;
    }
}

int search_key(List* student_list, int key, Student *student){
    if(student_list == NULL){
        return 0;
    }

    No *no = *student_list;

    while(no != NULL && no->data.id != key){
        no = no->next;
    }

    if(no == NULL){
        return 0;
    }
    else{
        *student = no->data;
        return 1;
    }
}

void print_list(List* student_list){
    if(student_list == NULL){
        return ;
    }

    if((*student_list) == NULL){
        return ;
    }

    No *no = *student_list;
    while(no != NULL){
        printf("\nmatricula: %d\n", no->data.id);
        printf("nome: %s\n", no->data.name);
        printf("notas: %.2f %.2f %.2f\n", no->data.test[0],
           no->data.test[1], no->data.test[2]);

        no = no->next;
    }
    printf("\n");

}
