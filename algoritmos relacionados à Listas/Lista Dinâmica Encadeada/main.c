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

    print_list(student_list);

    Student student4, student5;

    int search_result1 = search_position(student_list, 2, &student4);
    int search_result2 = search_key(student_list, 3, &student5);

    printf("Resultado da search: %d %d\n", search_result1, search_result2);

    int remove_result1 = remove_beginning(student_list);
    int remove_result2 = remove_end(student_list);
    int remove_result3 = remove_list(student_list, 2);

    printf("Resultado da remotion: %d %d %d\n", remove_result1, remove_result2,
           remove_result3);

    Student student1 = {1, "Pedro", 9, 8, 10};
    
    int add_result1 = add_beginning(student_list, student1);
    printf("Resultado da adition: %d\n", add_result1);

    free_list(student_list);
    return 0;
}
