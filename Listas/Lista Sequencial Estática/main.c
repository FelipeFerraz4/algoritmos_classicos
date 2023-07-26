#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main() {

    List *list;
    list = create_list();
    int size = size_list(list);
    int fullList = full_list(list);
    //if(full_list(list))

    free_list(list);

    return 0;
}
