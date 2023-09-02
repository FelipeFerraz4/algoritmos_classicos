#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    SequentialList* list_int;

    list_int = create_list();

    int result[8];
    int number[5] = {7, 21, 34, 65, 78};

    for(int i = 0; i < 5; i++){
        result[i] = insertElement(list_int, number[i]);
    }

    for (int i = 0; i < 5; i++){
        printf("%d ", list_int->list_int[i]);
    }

    printf("\n");

    result[6] = removeElement(list_int, 1);
    result[7] = removeElement(list_int, 3);

    for (int i = 0; i < 3; i++){
        printf("%d ", list_int->list_int[i]);
    }

    printf("\n");

    result[8] = searchElement(list_int, 34);
    printf("%d\n", list_int->list_int[result[8]]);

    printf("Hello world!\n");

    free_list(list_int);
    return 0;
}
