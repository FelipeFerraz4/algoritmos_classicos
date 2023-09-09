#include <stdio.h>
#include <stdlib.h>

int contarPalavras(char* frase){
    int i = 0;
    int count = 0;
    int status = 1; // parametro para ver se a posição anterior também tinha separação
    while(frase[i] != '\0'){
        if(frase[i] == '\t' || frase[i] == '\n' || frase[i] == ' ' || frase[i] == '_'){
            if(status != 1){
                count++;
                status = 1;
            }
        }
        else{
            status = 0;
        }
        i++;
    }

    if(status != 1){
        count++;
    }

    return count;
}

int main()
{
    char string1[] = "banana macaxeira";
    char string2[] = "banana\tmacaxeira";
    char string3[] = "banana_macaxeira";
    char string4[] = "banana\nmacaxeira";
    char string5[] = "banana macaxeira ";
    char string6[] = "banana  macaxeira";
    char string7[] = "   ";
    char string8[] = "   \t\t\t\t   \t";

    int resultado[8];

    resultado[0] = contarPalavras(string1);
    resultado[1] = contarPalavras(string2);
    resultado[2] = contarPalavras(string3);
    resultado[3] = contarPalavras(string4);
    resultado[4] = contarPalavras(string5);
    resultado[5] = contarPalavras(string6);
    resultado[6] = contarPalavras(string7);
    resultado[7] = contarPalavras(string8);

    for(int i = 0; i < 8; i++){
        printf("%d ", resultado[i]);
    }

    printf("Hello world!\n");
    return 0;
}
