#include <stdio.h>
#include <stdlib.h>

float soma(float number[2]){
    return number[0] + number[1];
}
float elevado(float number){
    return number * number;
}

float soma_quadrada(float number[2]){
    float number_quadrados[2];
    number_quadrados[0] = elevado(number[0]);
    number_quadrados[1] = elevado(number[1]);
    return soma(number_quadrados);
}

int main()
{
    float number[2];
    printf("Digite um numero: \n");
    scanf("%f", &number[0]);

    printf("Digite um numero: \n");
    scanf("%f", &number[1]);

    float sum = soma(number);
    float sum_squared = soma_quadrada(number);

    printf("Soma = %.2f\n", sum);
    printf("Soma quadrada = %.2f\n", sum_squared);
    return 0;
}
