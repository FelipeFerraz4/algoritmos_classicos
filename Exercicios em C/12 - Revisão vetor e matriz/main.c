#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE_ARRAY_MAX 10
#define SIZE_MATRIX 5
#define RAND_MAX_ARRAY 100
#define NAME_MAX 50
#define ADDRESS_MAX 100

typedef struct student{
    int age;
    char name[NAME_MAX];
    char address[ADDRESS_MAX];
}Student;

void get_user_number(int array_int[],int size_array){
    for(int i = 0; i < size_array; i++){
        printf("Digite um number inteiro: \n");
        scanf("%d", &array_int[i]);
    }
}

void get_sequential_number(int array_int[], int size_array){
    int first_number;
    printf("Digite o primeiro number: \n");
    scanf("%d", &first_number);

    int counter = 0;
    for(int i = first_number; i < (first_number+size_array); i++){
        array_int[counter] = i;
        counter++;
    }
}

void get_random_number(int array_int[], int size_array){
    for(int i = 0; i < size_array; i++){
        array_int[i] = rand() % RAND_MAX_ARRAY;
    }
}

void print_array(int array_int[], int size_array){
    for(int i = 0; i < size_array; i++){
        printf("%d ", array_int[i]);
    }
    printf("\n");
}

void print_array_inverted(int array_int[], int size_array){
    for(int i = size_array-1; i >= 0; i--){
        printf("%d ", array_int[i]);
    }
    printf("\n");
}

int sum_array(int array_int[], int size_array){
    int sum = 0;
    for(int i = 0; i < size_array; i++){
        sum += array_int[i];
    }
    return sum;
}

void extreme_vaues(int array_int[], int size_array,int *big, int *small){
    for(int i = 0; i < size_array; i++){
        if(i == 0){
            *big = array_int[i];
            *small = array_int[i];
        }
        else{
            if(array_int[i] > *big){
                *big = array_int[i];
            }

            if(array_int[i] < *small){
                *small = array_int[i];
            }
        }
    }
}

int counter_element(int array_int[], int size_array){
    int number, counter = 0;

    print_array(array_int, size_array);

    printf("Escolha o number: \n");
    scanf("%d", &number);

    for(int i = 0; i < size_array; i++){
        if(array_int[i] == number){
            counter++;
        }
    }

    return counter;
}

void identity_matrix(int size_matrix, int matrix[size_matrix][size_matrix]){
    for(int i = 0; i < size_matrix; i++){
        for(int j = 0; j < size_matrix; j++){
            if(i == j){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }
}

void print_matrix(int size_matrix, int matrix[size_matrix][size_matrix]){
    for(int i = 0; i < size_matrix; i++){
        for(int j = 0; j < size_matrix; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void biggest_element_matrix(int size_matrix,
                            int matrix[size_matrix][size_matrix],
                            int* line, int* column){
    int biggest;
    for(int i = 0; i < size_matrix; i++){
        for(int j = 0; j < size_matrix; j++){
            if(i == 0 && j == 0){
                biggest = matrix[i][j];
                *line = i;
                *column = j;
            }
            else{
                if(matrix[i][j] > biggest){
                    biggest = matrix[i][j];
                    *line = i;
                    *column = j;
                }
            }
        }
    }
}

void rand_matrix(int size_matrix, int matrix[size_matrix][size_matrix]){
    for(int i = 0; i < size_matrix; i++){
        for(int j = 0; j < size_matrix; j++){
            matrix[i][j] = rand() % RAND_MAX_ARRAY;
        }
    }
}

Student get_Student(){
    Student student;

    printf("Digite seu nome: \n");
    fllush(stdin);
    gets(student.name);

    printf("Digite sua idade: \n");
    scanf("%d", student.age);

    printf("Digite o seu address: \n");
    fllush(stdin);
    gets(student.address);

    return student;
}

void print(Student student){

}

int main()
{
    srand((unsigned)time(NULL));
    int array_int[SIZE_ARRAY_MAX];
    int matrix[SIZE_MATRIX][SIZE_MATRIX];
    int sum, big, small, times_number, line, column;
    float mean;

    get_random_number(array_int, SIZE_ARRAY_MAX);

    print_array(array_int, SIZE_ARRAY_MAX);

    print_array_inverted(array_int, SIZE_ARRAY_MAX);

    sum = sum_array(array_int, SIZE_ARRAY_MAX);

    mean = (float) sum/SIZE_ARRAY_MAX;

    extreme_vaues(array_int, SIZE_ARRAY_MAX, &big, &small);

    printf("Soma do array: %d\n", sum);

    printf("Mean of array: %.2f\n", mean);

    printf("O maior: %d e o menor: %d\n", big, small);

    //times_number = counter_element(array_int, SIZE_ARRAY_MAX);
    //printf("O number apareceu %d vezes\n", times_number);

    identity_matrix(SIZE_MATRIX, matrix);

    print_matrix(SIZE_MATRIX, matrix);

    printf("\n");

    rand_matrix(SIZE_MATRIX, matrix);
    print_matrix(SIZE_MATRIX, matrix);

    biggest_element_matrix(SIZE_MATRIX, matrix, &line, &column);
    printf("O maior elemento esta na linha %d e coluna %d", line, column);



    return 0;
}
