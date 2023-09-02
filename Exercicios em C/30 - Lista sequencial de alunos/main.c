#include <stdio.h>
#include <stdlib.h>
#include "ListaSequecial.h"

int main()
{
    Lista* lista;
    lista = cria_lista();

    int resultado[10];

    resultado[0] = tamanho_lista(lista);
    printf("Tamanho: %d\n", resultado[0]);

    resultado[1] = lista_cheia(lista);
    printf("Lista cheia: %d\n", resultado[1]);

    resultado[2] = lista_vazia(lista);
    printf("Lista Vazia: %d\n", resultado[2]);

    Aluno alunos1 = {10, "Vanessa", 8, 9, 8};
    Aluno alunos2 = {11, "Beatriz", 10, 9, 9};
    Aluno alunos3 = {12, "Kaio", 8, 9, 9};

    resultado[3] = insere_lista_inicio(lista, alunos1);
    resultado[4] = insere_lista_final(lista, alunos2);
    resultado[5] = insere_lista_ordenada(lista, alunos3);
    imprime_lista(lista);

    libera_lista(lista);
    return 0;
}
