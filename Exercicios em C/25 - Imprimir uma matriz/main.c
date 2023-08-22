#include <stdio.h>
#include <stdlib.h>

void print_matriz(int size_array, int matriz[size_array][size_array]){
    for(int i = 0; i < size_array; i++){
        for(int j = 0; j < size_array; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matriz[3][3] = {{2,3,4},{5,2,4},{9,2,4}};
    print_matriz(3, matriz);
    return 0;
}
