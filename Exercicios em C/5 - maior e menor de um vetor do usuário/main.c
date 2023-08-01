#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_array;
    float smaller, biggest;
    
    printf("Digite a quantidade de numeros do vetor: \n");
    scanf("%d", &size_array);
    
    float* array = (float*) malloc(sizeof(float) * size_array);
    
    for(int i = 0; i < size_array; i++){
        printf("Digite um numero real: \n");
        scanf("%f", &array[i]);
        
        if(i == 0){
            smaller = array[i];
            biggest = array[i];
        }
        else{
            if(array[i] < smaller){
                smaller = array[i];
            }
            
            if(array[i] > biggest){
                biggest = array[i];
            }
        }
    }
    
    printf("O maior: %.2f e o menor: %.2f\n", smaller, biggest);
    
    free(array);
    
    return 0;
}
