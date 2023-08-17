#include <stdio.h>
#include <stdlib.h>

#define SIZE_STUDENT 2
#define NAME_MAX 50
#define SIZE_TEST 3

typedef struct student{
    int id;
    char nome[NAME_MAX];
    float test[SIZE_TEST];
}Student;

void get_student(Student students[SIZE_STUDENT],
                 int size_student){
    for(int i = 0; i < size_student; i++){
        printf("Digite o ID do estudante: \n");
        scanf("%d", &students[i].id);

        printf("Digite o nome do estudante: \n");
        fflush(stdin);
        gets(students[i].nome);

        for(int j = 0; j < SIZE_TEST; j++){
            printf("Digite a nota do teste %d: \n", j+1);
            scanf("%f", &students[i].test[j]);
        }
        printf("\n");
    }
}

int biggest_mean(Student student[SIZE_STUDENT],
                 int size_student){
    int biggest_id;
    float mean = 0;
    for(int i = 0; i < size_student; i++){
        float aux_mean = 0;

        for(int j = 0; j <SIZE_TEST;j++){
                aux_mean += student[i].test[j];
        }

        aux_mean /= SIZE_TEST;

        if(i == 0){
            biggest_id = 0;
            mean = aux_mean;
        }
        else{
            if(aux_mean > mean){
                mean = aux_mean;
                biggest_id = i;
            }
        }
    }
    return biggest_id+1;
}

int main()
{
    Student students[SIZE_STUDENT];
    get_student(students, SIZE_STUDENT);
    int id = biggest_mean(students, SIZE_STUDENT);
    printf("A maior media e do estudante %d\n", id);
    return 0;
}
