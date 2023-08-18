#include <stdio.h>
#include <stdlib.h>

int calculadora(){
    int option;
    do{
        printf("Digite o codigo da option: \n");
        printf("1 - Soma\n");
        printf("2 - Diferenca\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("0 - Sair\n");
        scanf("%d", &option);
    }while(option < 0 && option > 4);
    return option;
}


float option_calculator(int option, float number1, float number2){
    float result = 0;
    if(option == 1){
        result = number1 + number2;
    }
    else if(option == 2){
        result = number1 - number2;
    }
    else if(option == 3){
        result = number1 * number2;
    }
    else{
        if(number2 == 0){
            printf("Erro, impossivel divisao por 0\n");
            result = 0;
        }
        else{
            result = number1 / number2;
        }
    }

    return result;
}

int main()
{
    int option = 0;
    do{
        float result;
        option = calculadora();
        if(option != 0){
            float number1, number2;
            printf("Digite um numero: \n");
            scanf("%f", &number1);

            printf("Digite um numero: \n");
            scanf("%f", &number2);

            result = option_calculator(option, number1, number2);
            printf("Resultado = %.3f\n", result);
        }

    }while(option != 0);
    return 0;
}
