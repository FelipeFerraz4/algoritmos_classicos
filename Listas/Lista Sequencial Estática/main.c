#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main() {

    List *list_student;
    list_student = create_list();
    int size = size_list(list_student);
    int fullList = full_list(list_student);
    //if(full_list(list_student))
    int emptyList = empty_list(list_student);
    //if(empty_list(list_student))
    Student student1, student2, student3;
    student1.ID = 2;
    strcmp(student1.name, "Vanessa");
    student1.test1 = 9;
    student1.test2 = 10;
    student1.test3 = 8;

    student2.ID = 1;
    strcmp(student2.name, "Beatriz");
    student2.test1 = 9.5;
    student2.test2 = 9;
    student2.test3 = 10;

    student3.ID = 3;
    strcmp(student3.name, "Marata");
    student3.test1 = 7;
    student3.test2 = 9;
    student3.test3 = 8;

    int result1 = add_list_element(list_student, student1);
    int result2 = add_beginning_list(list_student, student2);
    int result3 = add_sort_list(list_student, student3);

    printf("ponto %d\n", list_student->data[0].ID);
    printf("ponto %d\n", list_student->data[1].ID);
    printf("ponto %d\n", list_student->data[2].ID);

    free_list(list_student);

    return 0;
}
