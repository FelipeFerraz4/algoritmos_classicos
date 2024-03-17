#include <stdio.h>
#include <stdlib.h>
#include "tableHash.h"
#include "filaDePrioridades.h"

#define SIZE_HASH 53

int teste_hash(){
    TableHash* hash_nave;
    hash_nave = cria_hash();

    insereHash(hash_nave, 1, 2, 3);
    insereHash(hash_nave, 1, 4, 3);
    insereHash(hash_nave, 5, 2, 3);
    insereHash(hash_nave, 6, 2, 5);
    insereHash(hash_nave, 3, 2, 1);

    print_hash(hash_nave);

    int resultado[3];
    resultado[0] = buscaHash(hash_nave, 1, 2, 3);
    printf("Resultado da busca: %d\n", resultado[0]);
    resultado[1] = buscaHash(hash_nave, 5, 2, 3);
    printf("Resultado da busca: %d\n", resultado[1]);
    resultado[1] = buscaHash(hash_nave, 50, 22, 32);
    printf("Resultado da busca: %d\n", resultado[1]);

    insereHash(hash_nave, 1, 2, 3);
    print_hash(hash_nave);

    remove_lista_Hash(hash_nave, 1, 4, 3);
    print_hash(hash_nave);

    verificaLista(hash_nave, 1, 2, 3);
    print_hash(hash_nave);

    insereHash(hash_nave, 1, 3, 2);
    insereHash(hash_nave, 2, 1, 3);
    insereHash(hash_nave, 2, 3, 1);
    insereHash(hash_nave, 3, 1, 2);
    print_hash(hash_nave);

    verificaLista(hash_nave, 1, 2, 3);
    print_hash(hash_nave);

    libera_hash(hash_nave);
    return 0;
}
