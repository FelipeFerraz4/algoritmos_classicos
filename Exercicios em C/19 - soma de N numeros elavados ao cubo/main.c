#include <stdio.h>
#include <stdlib.h>

int soma_numeros(int number){
    if(number == 0){
        return 0;
    }
    else{
        return (number*number*number) + soma_numeros(number-1);
    }
}

int main()
{
    int number;
    printf("Digite um numero: \n");
    scanf("%d", &number);

    number = soma_numeros(number);

    printf("A soma = %d\n", number);

    return 0;
}
