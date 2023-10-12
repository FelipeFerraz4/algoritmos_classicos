#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

#define MAX_TAMANHO_LINHA_FILE 500

Pessoa get_passageiro(int id){
    Pessoa passageiro;

    passageiro.id = id;

    printf("Digite o nome do passageiro: \n");
    scanf("%s", passageiro.nome);

    printf("Digite a idade do passageiro: \n");
    scanf("%d", &passageiro.idade);

    printf("Digite o planeta do passageiro: \n");
    scanf("%s", passageiro.planeta);

    return passageiro;
}

Recurso get_recurso(int id){
    Recurso recurso;

    recurso.id = id;

    printf("Nome do recurso transportado: \n");
    scanf("%s", recurso.nome);

    printf("Quantidade do recurso transportado: \n");
    scanf("%d", &recurso.quantidade);

    return recurso;
}

int pegar_quantidade(char item[]){
    int number;

    printf("%s: \n", item);
    scanf("%d", &number);

    return number;
}

int pegar_prioridade(){
    int prioridade;

    printf("Digita a prioridade da nave: \n");
    scanf("%d", &prioridade);

    return prioridade;
}

Nave pegar_nave(){
    Nave nave;

    printf("\nDigite abaixo os dados da nave.\n");

    nave.quantidade_pessoas = pegar_quantidade("Digite a quantiadade de passageiro da nave");

    for(int i = 1; i <= nave.quantidade_pessoas; i++){
        printf("passageiro pegos\n");
    }

    nave.quantidade_recursos = pegar_quantidade("Digite a quantiadade de recursos da nave");

    for(int i = 1; i <= nave.quantidade_recursos; i++){
        printf("recusos pegos\n");
    }

    return nave;
}

int option_list(){
    int option = 1;

    do{
        printf("Escolha uma das alternativas.\n");
        printf("1 - inserir uma nova nave\n");
        printf("2 - remover uma nave\n");
        printf("0 - Sair do programa\n");
        printf("Digite a sua alternativa: ");
        scanf("%d", &option);
    }while(option < 0 && option >= 1);

    return option;
}

int option_programa(Heap* fila_de_naves){
    int option = 1;

    do{
        option = option_list();

        if(option == 0){
            break;
        }
        else if(option == 1){
            Nave nave = pegar_nave();
            int prioridade = pegar_prioridade();

            int priority = verifica_prioridade(prioridade);

            if(priority > prioridade){
                printf("Encontramos uma emergencia na nave e ela ganhou uma maior prioridade\n");
            }else if(priority < prioridade){
                printf("Encontramos um clandestino na nave e a prioridade dela diminui para provomer uma melhor exame da nave\n");
            }

            //inserir_heap(fila_de_naves, nave, priority);
            printf("Nave adicionada com sucesso\n");
        }
        else {
            printf("Removido com sucesso\n\n");
        }
    }while(option != 0);

    return option;
}

int get_nave_file(Heap* fila_de_naves){
    char buffer[MAX_TAMANHO_LINHA_FILE];
    int count = 0;

    FILE* file = fopen("naves.csv", "r");

    if (file == NULL){
        printf("Erro ao abrir o arquivo. \n");
        return 0;
    }

    //paga a primeira linha da lista, que tem o nome dos parametos
    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);

    //leitura do arquivo até ler uma linha nula
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        Dados dados;
        Nave nave;

        char prioridade[20];
        strcpy(prioridade, strtok(buffer, ","));
        dados.prioridade = atoi(prioridade);

        char quantidade_passageiros[20];
        strcpy(quantidade_passageiros, strtok(NULL, ","));
        nave.quantidade_pessoas = atoi(quantidade_passageiros);

        for(int i = 0; i < nave.quantidade_pessoas; i++) {
            Pessoa passageiro;

            char id_passageiro[20];
            strcpy(id_passageiro, strtok(NULL, ","));
            passageiro.id = atoi(id_passageiro);

            char nome_passageiro[100];
            strcpy(nome_passageiro, strtok(NULL, ","));
            strcpy(passageiro.nome ,nome_passageiro);

            char idade_passageiro[20];
            strcpy(idade_passageiro, strtok(NULL, ","));
            passageiro.idade = atoi(idade_passageiro);

            char planeta_passageiro[100];
            strcpy(planeta_passageiro, strtok(NULL, ","));
            strcpy(passageiro.planeta ,planeta_passageiro);

            nave.pessoa[i] = passageiro;
        }

        char quantidade_recursos[20];
        strcpy(quantidade_recursos, strtok(NULL, ","));
        nave.quantidade_recursos = atoi(quantidade_recursos);

        for(int i = 0; i < nave.quantidade_recursos; i++){
            Recurso recurso;

            char id_recurso[20];
            strcpy(id_recurso, strtok(NULL, ","));
            recurso.id = atoi(id_recurso);

            char nome_produto[100];
            strcpy(nome_produto, strtok(NULL, ","));
            strcpy(recurso.nome ,nome_produto);

            char quantidade_produto[20];
            strcpy(quantidade_produto, strtok(NULL, ","));
            recurso.quantidade = atoi(quantidade_produto);

            nave.recurso[i] = recurso;
        }

        dados.nave = nave;
        fila_de_naves->dados[count] = dados;
        count++;

    }

    fila_de_naves->quantidade_nave = count;
    return 1;
}
