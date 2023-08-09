#include <stdio.h>
#include <Lista.h>

int main() {
    List* student_list;
    student_list = create_list();
    
    int size = size_list(student_list);
    printf("Tamanho da list: %d\n", size);
    
    int empty = empty_list(student_list);
    printf("Lista vazia: %d\n", empty);
    
    printf("Hello world");
    
    free_list(student_list);

    return 0;
}
