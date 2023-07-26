#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main() {

    List *list;
    list = create_list();
    int size = size_list(list);
    int fullList = full_list(list);
    //if(full_list(list))
    int emptyList = empty_list(list);
    //if(empty_list(list))
    Student student1, student2;
    student1.ID = 1;
    strcmp(student1.name, "Vanessa");
    student1.test1 = 9;
    student1.test2 = 10;
    student1.test3 = 8;
    
    student2.ID = 2;
    strcmp(student2.name, "Beatriz");
    student2.test1 = 9.5;
    student2.test2 = 9;
    student2.test3 = 10;
    
    int result1 = add_list_element(list, student1);
    int result2 = add_beginning_list(list, student2);

    free_list(list);
    printf("ponto %d\n", list->data[0].ID);
    printf("ponto %d\n", list->data[1].ID);

    return 0;
}
