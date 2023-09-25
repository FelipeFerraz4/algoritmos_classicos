#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    Heap *fila_de_naves;
    fila_de_naves = criar_heap();

    printf("tamanho:%d cheio:%d vazio:%d\n",
           tamanho_heap(fila_de_naves), heap_cheio(fila_de_naves),
           heap_vazio(fila_de_naves));

    printf("Hello world!\n");

    libera_heap(fila_de_naves);
    return 0;
}
