#include <stdio.h>
#include <stdlib.h>

#define NOME_MAX 50
#define NUMERO_PRODUTOS 4

typedef struct produto{
    char nome[NOME_MAX];
    float custo;
    int quantidade;
}Produto;

void add_carrinho(int carrinho[][2], int produto, int quantidade){
    for(int i = 0; i < NUMERO_PRODUTOS; i++){
        if(carrinho[i][0] == produto){
            carrinho[i][1] += quantidade;
            return;
        }

        if(carrinho[i][0] == 0){
            carrinho[i][0] = produto;
            carrinho[i][1] = quantidade;
            return;
        }
    }
    printf("Nao pode adicionar\n");

}

float custo_total(int carrinho[][2], Produto produtos[]){
    float total = 0;

    for(int i = 0; i < NUMERO_PRODUTOS; i++){
        if(carrinho[i][0] != 0){
            total += produtos[carrinho[i][0]-1].custo*carrinho[i][1];
        }
    }

    return total;
}

void finalizar_comprar(int carrinho[][2], Produto produto[]){
    for(int i = 0; i < NUMERO_PRODUTOS; i++){
        if(carrinho[i][0] != 0){
            produto[carrinho[i][0] -1].quantidade -= carrinho[i][1];
        }
    }
    carrinho = 0;
}



int main(){
    int carrinho[NUMERO_PRODUTOS][2] = {0};
    Produto produtos[NUMERO_PRODUTOS]={"miojo de carne",5.50,20,"miojo de frango",6.0,50,"miojo de pizza",7.0,20,"miojo vegetariano",3.0,100};

    int escolha = 0;

    do{
        printf("Escolha a option: \n"\
               "1 - Adicionar produto\n"\
               "2 - Mostrar custo total\n"
               "0 - Finalizar compra\n");
        scanf("%d", &escolha);

        if(escolha == 1){
            int id, quantidade;
            printf("Escolha um produto: \n");
            for(int i = 0; i < NUMERO_PRODUTOS; i++){
                printf("%d - %s\n",i+1 ,produtos[i].nome);
            }
            scanf("%d", &id);
            printf("Digite a quantidade: \n");
            scanf("%d", &quantidade);

            add_carrinho(carrinho, id, quantidade);
        }
        else if(escolha == 2){
            float total = custo_total(carrinho, produtos);
            printf("%.2f\n", total);
        }
        else if(escolha == 0){
            finalizar_comprar(carrinho, produtos);
        }
        else{
            printf("Option invalida\n");
        }
    }while(escolha != 0);

}
