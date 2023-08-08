#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

int main()
{
    Product product1;
    printf("Digite a identificacao do produto: \n");
    scanf("%d", &product1.id);

    char name[50];
    printf("Digite o nome do produto: \n");
    fflush(stdin);
    gets(name);
    strcpy(product1.name, name);

    printf("Digite a quantidade: \n");
    scanf("%d", &product1.quantity);


    printf("Digite o valor do produto: \n");
    scanf("%f", &product1.price);

    printf("ID: %d\n", product1.id);
    printf("Nome: %s\n", product1.name);
    printf("Quantidade: %d\n", product1.quantity);
    printf("Preco: %.2f", product1.price);

    return 0;
}
