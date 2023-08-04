#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main()
{
    List *student_list;
    student_list = create_list();

    int size_list_result = size_list(student_list);
    printf("Tamanho da lista: %d\n", size_list_result);

    int empty_list_result = empty_list(student_list);
    printf("A lista esta vazia: %d\n", empty_list_result);

    Student student1 = {1, "Maria",{8,9,10}};
    Student student2 = {2, "Clara",{9.5,9,10}};
    Student student3 = {3, "Marcos",{8,8.5,9}};
    /*
    Student student1;
    student1.id = 1;
    strcpy(student1.name, "Maria");
    student1.test[0] = 8;
    student1.test[0] = 9;
    student1.test[0] = 10;
    */

    int add_result1 = add_beginnig(student_list, student1);
    int add_result2 = add_end(student_list, student2);
    int add_result3 = add_sort(student_list, student3);

    printf("Resultado da adition: %d %d %d\n", add_result1, add_result2, add_result3);
/*
    printf("\nmatricula: %d\n", student_list->data.id);
    printf("nome: %s\n", student_list->data.name);
    printf("notas: %.2f %.2f %.2f\n", student_list->data.test[0],
           student_list->data.test[1], student_list->data.test[2]);
*/
    free_list(student_list);
    printf("Hello world!\n");
    return 0;
}
