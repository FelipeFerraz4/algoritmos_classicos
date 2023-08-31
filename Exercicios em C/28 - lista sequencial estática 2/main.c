#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    SequentialList* list_int;

    list_int = create_list();

    int result_add[5];
    int number[5] = {7, 21, 34, 65, 78};

    for(int i = 0; i < 5; i++){
        result_add[i] = insertElement(list_int, number[i]);
    }

    for (int i = 0; i < 5; i++){
        printf("%d ", list_int->list_int[i]);
    }

    printf("Hello world!\n");

    free_list(list_int);
    return 0;
}
