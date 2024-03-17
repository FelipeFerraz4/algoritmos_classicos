#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDePrioridades.h"

#define MAX_TAMANHO_LINHA_FILE 500

Pessoa pegar_pessoa(int id){
    Pessoa pessoa;

    pessoa.id = id;

    printf("Digite o nome do pessoa: \n");
    fflush(stdin);
    gets(pessoa.nome);

    printf("Digite a idade do pessoa: \n");
    scanf("%d", &pessoa.idade);

    printf("Digite o planeta do pessoa: \n");
    fflush(stdin);
    gets(pessoa.planeta);

    return pessoa;
}

Recurso pegar_recurso(int id){
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

    printf("Digite o nome da nave: \n");
    fflush(stdin);
    gets(nave.nome);

    nave.quantidade_pessoas = pegar_quantidade("Digite a quantiadade de pessoas da nave");

    for(int i = 0; i < nave.quantidade_pessoas; i++){
        nave.pessoa[i] = pegar_pessoa(i+1);
    }

    nave.quantidade_recursos = pegar_quantidade("Digite a quantiadade de recursos da nave");

    for(int i = 0; i < nave.quantidade_recursos; i++){
        nave.recurso[i] = pegar_recurso(i+1);
    }

    return nave;
}

int option_list(){
    int option = 1;

    do{
        printf("Escolha uma das alternativas.\n");
        printf("1 - inserir uma nova nave\n");
        printf("2 - remover uma nave\n");
        printf("3 - Mostra naves cadastradas\n");
        printf("4 - Mostra lista de item das naves\n");
        printf("5 - Mostra tabela hash\n");
        printf("0 - Sair do programa\n");
        printf("Digite a sua alternativa: ");
        scanf("%d", &option);

        if(option < 0 || option > 5){
            printf("Erro, alternativa nao encontrada\n\n");
        }

    }while(option < 0 || option > 5);

    return option;
}

int option_programa(Heap* fila_de_naves, TableHash* hash_nave){
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

            inserir_heap(fila_de_naves, nave, priority);
            printf("Nave adicionada com sucesso\n\n");
        }
        else if(option == 2){
            int ids_recursos[3];
            remove_heap_ids(fila_de_naves, ids_recursos);
            insereHash(hash_nave, ids_recursos[0], ids_recursos[1], ids_recursos[2]);
            int fendaDimensional = verificaLista(hash_nave, ids_recursos[0], ids_recursos[1], ids_recursos[2]);
            if(fendaDimensional == 1){
                    printf("A FENDA DIMENSIONAL AUMENTOU, AVANCEM NAVES RAPIDO RAPIDO\n");
                for(int k = 0; k < 10; k++){
                    remove_heap_ids(fila_de_naves, ids_recursos);
                    if(k == 0){
                        printf("UMA NAVE PASSOU\n");
                    }
                    else{
                        printf("MAIS UMA NAVE PASSOU, RAPIDO\n");
                    }
                }
            }
            printf("Nave removida com sucesso\n\n");
        }
        else if(option == 3){
            for(int k = 0; k < tamanho_heap(fila_de_naves); k++){
                printf("%d -> %d - ", k, fila_de_naves->dados[k].prioridade);
                printf("%s\n", fila_de_naves->dados[k].nave.nome);
            }
            printf("\n");
        }
        else if(option == 4){
            for(int k = 0; k < tamanho_heap(fila_de_naves); k++){
                printf("%d -> %d - ", k, fila_de_naves->dados[k].prioridade);
                Nave nave = fila_de_naves->dados[k].nave;
                printf("%s\n\n", nave.nome);
                for(int i = 0; i < nave.quantidade_pessoas; i++){
                    Pessoa pessoa = nave.pessoa[i];
                    printf("%d - ", pessoa.id);
                    printf("%s - ", pessoa.nome);
                    printf("%d - ", pessoa.idade);
                    printf("%s\n", pessoa.planeta);
                }
                printf("\n");
                for(int i = 0; i < nave.quantidade_recursos; i++){
                    Recurso recurso = nave.recurso[i];
                    printf("%d - ", recurso.id);
                    printf("%s - ", recurso.nome);
                    printf("%d\n", recurso.quantidade);
                }
                printf("\n---------------------------------------------------------------------------------\n");
            }

            printf("\n");
        }
        else{
            print_hash(hash_nave);
        }
    }while(option != 0);

    return option;
}

int get_nave_file(Heap* fila_de_naves){
    char buffer[MAX_TAMANHO_LINHA_FILE];

    FILE* file = fopen("naves.csv", "r");

    if (file == NULL){
        printf("Erro ao abrir o arquivo. \n");
        return 0;
    }

    //paga a primeira linha da lista, que tem o nome dos parametos
    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);

    //leitura do arquivo at� ler uma linha nula
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        int priority;
        Nave nave;

        char prioridade[20];
        strcpy(prioridade, strtok(buffer, ","));
        priority = atoi(prioridade);

        char nome_nave[100];
        strcpy(nome_nave, strtok(NULL, ","));
        strcpy(nave.nome ,nome_nave);

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

        inserir_heap(fila_de_naves, nave, priority);
    }
    return 1;
}
