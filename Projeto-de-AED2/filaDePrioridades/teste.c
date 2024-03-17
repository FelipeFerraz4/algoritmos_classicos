#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filaDePrioridades.h"

void teste_heap(Heap* fila_de_naves){
    srand((unsigned)time(NULL));

    printf("tamanho:%d cheio:%d vazio:%d\n",
           tamanho_heap(fila_de_naves), heap_cheio(fila_de_naves),
           heap_vazio(fila_de_naves));

    Nave nave;

    strcpy(nave.nome, "alvaro alberto");
    nave.pessoa[0].id = 1;
    nave.pessoa[0].idade = 20;
    strcpy(nave.pessoa[0].nome, "leticia");
    strcpy(nave.pessoa[0].planeta, "kepler");

    nave.quantidade_pessoas = 1;

    strcpy(nave.recurso[0].nome, "leite");
    nave.recurso[0].quantidade = 500;

    nave.quantidade_recursos = 1;

    printf("\n");

    for(int i = 0; i < nave.quantidade_pessoas; i++){
        printf("Nome: %s\n", nave.pessoa[i].nome);
        printf("Id: %d\n", nave.pessoa[i].id);
        printf("Idade: %d\n", nave.pessoa[i].idade);
        printf("Planeta: %s\n", nave.pessoa[i].planeta);
    }

    printf("\n");

    for(int i = 0; i < nave.quantidade_recursos; i++){
        printf("Nome: %s\n", nave.recurso[0].nome);
        printf("Quantidade: %d\n", nave.recurso[0].quantidade);
    }

    printf("\n");

    inserir_heap(fila_de_naves, nave, verifica_prioridade(50));
    inserir_heap(fila_de_naves, nave, verifica_prioridade(40));
    inserir_heap(fila_de_naves, nave, verifica_prioridade(80));
    inserir_heap(fila_de_naves, nave, verifica_prioridade(10));

    for(int k = 0; k < tamanho_heap(fila_de_naves); k++){
        printf("%d - ", fila_de_naves->dados[k].prioridade);
        printf("%s\n", fila_de_naves->dados[k].nave.nome);
    }

    printf("\n");
    remove_heap(fila_de_naves);

    for(int k = 0; k < tamanho_heap(fila_de_naves); k++){
        printf("%d - ", fila_de_naves->dados[k].prioridade);
        printf("%s\n", fila_de_naves->dados[k].nave.nome);
    }

    printf("\n");

    for(int i = 0; i  < 10; i++){
        int prioridade = verifica_prioridade(10);
        printf("fim: %d\n", prioridade);
    }

}
