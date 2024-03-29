#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct student {
    int ID;
    char name[30];
    float test1, test2, test3;
} Student;

void print_element_list(void* student){
    Student *student1 = student;
    //printf("--------------------------------------------------------\n");
    printf("Matricula: %d\n", student1->ID);
    printf("Nome: %s\n", student1->name);
    printf("Notas: %.2f %.2f %.2f\n", student1->test1,
           student1->test2, student1->test3);
    printf("--------------------------------------------------------\n");
}

int main()
{
    List* generic_list;
    generic_list = create_list(sizeof(Student));

    Student student1, student2, student3;

    student1.ID = 1;
    strcpy(student1.name,"Beatriz");
    student1.test1 = 9.5;
    student1.test2 = 9;
    student1.test3 = 10;

    student2.ID = 2;
    strcpy(student2.name,"Vanessa");
    student2.test1 = 9;
    student2.test2 = 10;
    student2.test3 = 8;

    student3.ID = 3;
    strcpy(student3.name,"Marata");
    student3.test1 = 7;
    student3.test2 = 9;
    student3.test3 = 8;

    int add_result1 = add_sort_list(generic_list, 1, &student1);
    int add_result2 = add_sort_list(generic_list, 2, &student2);
    int add_result3 = add_sort_list(generic_list, 3, &student3);

    printf("Resultado da adition: %d %d %d\n", add_result1, add_result2, add_result3);

    Student student4, student5, student6;
    int search_result1 = search_list(generic_list, 1, &student4);
    int search_result2 = search_list(generic_list, 2, &student5);
    int search_result3 = search_list(generic_list, 3, &student6);

    printf("Resultado da search: %d %d %d\n", search_result1,
           search_result2, search_result3);

    print_list(generic_list, print_element_list);


    int remove_result1 = remove_list(generic_list, 1);
    int remove_result2 = remove_list(generic_list, 2);
    int remove_result3 = remove_list(generic_list, 3);

    printf("Resultado da remove: %d %d %d\n", remove_result1, remove_result2,
           remove_result3);

    free_list(generic_list);

    return 0;
}
