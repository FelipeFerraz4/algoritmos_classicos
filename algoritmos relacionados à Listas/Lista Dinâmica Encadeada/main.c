#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    List* list_student;
    list_student = create_list();


    free_list(list_student);
    printf("Hello world!\n");
    return 0;
}
