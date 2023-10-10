#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int main()
{
    Heap *fila_de_naves;
    fila_de_naves = criar_heap();

    printf("tamanho:%d cheio:%d vazio:%d\n",
           tamanho_heap(fila_de_naves), heap_cheio(fila_de_naves),
           heap_vazio(fila_de_naves));

    Dados dados;

    dados.pessoa[0].id = 1;
    dados.pessoa[0].idade = 20;
    strcpy(dados.pessoa[0].nome, "leticia");
    strcpy(dados.pessoa[0].planeta, "kepler");

    dados.quantidade_pessoas = 1;

    strcpy(dados.recurso[0].nome, "leite");
    dados.recurso[0].quantidade = 500;

    dados.quantidade_recursos = 1;

    printf("\n");

    for(int i = 0; i < dados.quantidade_pessoas; i++){
        printf("Nome: %s\n", dados.pessoa[i].nome);
        printf("Id: %d\n", dados.pessoa[i].id);
        printf("Idade: %d\n", dados.pessoa[i].idade);
        printf("Planeta: %s\n", dados.pessoa[i].planeta);
    }

    printf("\n");

    for(int i = 0; i < dados.quantidade_recursos; i++){
        printf("Nome: %s\n", dados.recurso[0].nome);
        printf("Quantidade: %d\n", dados.recurso[0].quantidade);
    }

    printf("\n");

    inserir_heap(fila_de_naves, dados, 70);

    for(int k = 0; k < tamanho_heap(fila_de_naves); k++){
        printf("%d - ", fila_de_naves->naves[k].prioridade);
        printf("%s\n", fila_de_naves->naves[k].dados.pessoa->nome);
    }

    printf("Hello world!\n");

    libera_heap(fila_de_naves);
    return 0;
}
