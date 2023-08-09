#include <stdio.h>
#include "Lista.h"

int main() {
    List* student_list;
    student_list = create_list();
    
    int size = size_list(student_list);
    printf("Tamanho da list: %d\n", size);
    
    int empty = empty_list(student_list);
    printf("Lista vazia: %d\n", empty);
    
    Student student1 = {1, "Pedro", 9, 8, 10};
    
    int add_result1 = add_beginning(student_list, student1);
    printf("Resultado da adition: %d\n", add_result1);
    
    free_list(student_list);

    return 0;
}
