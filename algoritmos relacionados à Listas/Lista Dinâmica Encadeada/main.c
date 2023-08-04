#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    List* student_list;
    student_list = create_list();

    int size_list_result = size_list(student_list);
    printf("Tamanho da lista: %d\n", size_list_result);

    int empty_list_result = empty_list(student_list);
    printf("A lista esta vazia: %d\n", empty_list_result);


    free_list(student_list);
    printf("Hello world!\n");
    return 0;
}
