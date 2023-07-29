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

    student2.ID = 1;
    strcpy(student2.name,"Beatriz");
    student2.test1 = 9.5;
    student2.test2 = 9;
    student2.test3 = 10;

    student1.ID = 2;
    strcpy(student1.name,"Vanessa");
    student1.test1 = 9;
    student1.test2 = 10;
    student1.test3 = 8;

    student3.ID = 3;
    strcpy(student3.name,"Marata");
    student3.test1 = 7;
    student3.test2 = 9;
    student3.test3 = 8;

    int add_result1 = add_end_list_element(list_student, student1);
    int add_result2 = add_beginning_list(list_student, student2);
    int add_result3 = add_sort_list(list_student, student3);

    printf("ponto %d\n", list_student->data[0].ID);
    printf("ponto %d\n", list_student->data[1].ID);
    printf("ponto %d\n", list_student->data[2].ID);

    printf("ponto %s\n", list_student->data[0].name);
    printf("ponto %s\n", list_student->data[1].name);
    printf("ponto %s\n", list_student->data[2].name);

    int remove_result1 = remove_end_list(list_student);
    int remove_result2 = remove_beginning_list(list_student);

    free_list(list_student);

    return 0;
}
