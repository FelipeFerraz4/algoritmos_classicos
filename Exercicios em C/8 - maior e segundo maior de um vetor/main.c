#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_LIST 10
#define RAND_MAX 100

void complete_List(int list[],int size,int rand_max){
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++){
        int num = (rand() % rand_max);
        list[i] = num;
    }
}

void print_List(int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

void bigger2_list(int list[], int size_list, int *big1, int *big2){
    for(int i = 0; i < size_list; i++){
        if(i == 0){
            *big1 = list[i];
            *big2 = list[i+1];
        }
        else if(list[i] > *big1){
            *big2 = *big1;
            *big1 = list[i];

        }
        else if(list[i] > *big2){
            *big2 = list[i];
        }
    }
}

int main()
{
    int list[SIZE_LIST];
    int bigger, second_bigger;

    complete_List(list, SIZE_LIST, RAND_MAX);
    print_List(list, SIZE_LIST);

    bigger2_list(list, SIZE_LIST, &bigger, &second_bigger);

    printf("Maior: %d\nSegundo maior: %d\n", bigger, second_bigger);

    printf("Hello world!\n");
    return 0;
}
