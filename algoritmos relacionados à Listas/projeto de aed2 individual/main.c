#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int main()
{
    Heap *fila_de_naves;
    fila_de_naves = criar_heap();

    get_nave_file(fila_de_naves);

    //teste_heap(fila_de_naves);
    option_programa(fila_de_naves);

    printf("Hello world!\n");

    libera_heap(fila_de_naves);

    return 0;
}
