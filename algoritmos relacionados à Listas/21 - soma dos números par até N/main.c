#include <stdio.h>
#include <stdlib.h>

int somaPar(int number){
    int sum = 0;
    for(int i = 0; i <= number;i+=2){
        sum += i;
    }
    return sum;
}

int main()
{
    int number;
    printf("Digite um numero: \n");
    scanf("%d", &number);

    number = somaPar(number);

    printf("A soma e %d\n", number);

    return 0;
}
