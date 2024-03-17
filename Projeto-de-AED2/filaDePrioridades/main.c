#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDePrioridades.h"
#include "tableHash.h"

int main()
{
    Heap *fila_de_naves;
    fila_de_naves = criar_heap();

    TableHash* hash_nave;
    hash_nave = cria_hash();

    get_nave_file(fila_de_naves);

    //teste_heap(fila_de_naves);
    option_programa(fila_de_naves, hash_nave);

    //teste_hash();

    printf("Hello world!\n");

    libera_hash(hash_nave);
    libera_heap(fila_de_naves);

    return 0;
}
