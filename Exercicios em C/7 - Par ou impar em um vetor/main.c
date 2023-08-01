#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_array;
    
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &size_array);
    
    int* array = (int*) malloc(sizeof(int) * size_array);
    
    for(int i = 0; i < size_array; i++){
        printf("Digite um numero: \n");
        scanf("%d", &array[i]);
    }
    
    for(int i = 0; i < size_array; i++){
        printf("%d ", array[i]);
        
        if(array[i] % 2 == 0){
            printf("e par\n");
        }
        else{
            printf("e impar\n");
        }
    }
    
}
