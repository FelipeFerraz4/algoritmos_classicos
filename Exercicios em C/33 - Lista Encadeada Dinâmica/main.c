#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    Lista* lista;
    lista = cria_lista();
    printf("tamanho: %d vazia: %d\n", tamanho_lista(lista),
           lista_vazia(lista));

    printf("Hello world!\n");

    libera_lista(lista);

    return 0;
}
