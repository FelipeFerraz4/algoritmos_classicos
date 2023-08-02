#include <stdio.h>
#include <stdlib.h>

#define SIZE_USER 5

int main()
{
    int age[SIZE_USER];
    int sum = 0;
    float mean;

    for(int i = 0; i < SIZE_USER; i++){
        printf("Digite sua idade: \n");
        scanf("%d", &age[i]);
        sum += age[i];
    }

    printf("/33soma de idade: %d\n", sum);
    mean = sum/SIZE_USER;
    printf("media de idade: %.2f\n", mean);
    return 0;
}
