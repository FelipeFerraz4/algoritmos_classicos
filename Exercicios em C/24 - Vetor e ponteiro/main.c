#include <stdio.h>
#include <stdlib.h>

void print_array(int size_array, int *array){
    for(int i = 0; i < size_array; i++){
        printf("%d ", array[i]);
    }
}

int main()
{
    int array[6] = {2, 34, 5, 1, 8, 9};
    print_array(6, array);
    return 0;
}
