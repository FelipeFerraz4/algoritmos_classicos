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
    Student student1;
    student1.ID = 2;
    strcmp(student1.name, "Sanessa");
    student1.test1 = 9;
    student1.test2 = 10;
    student1.test3 = 8;
    
    add_list_element(list, student1);

    free_list(list);
    printf("ponto %d", list->data[0].ID);

    return 0;
}
