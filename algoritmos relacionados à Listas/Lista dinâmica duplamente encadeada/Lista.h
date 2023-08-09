#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX_NAME 30
#define MAX_TEST 3

typedef struct student{
    int id;
    char name[MAX_NAME];
    float test[MAX_TEST];
}Student;

typedef struct no{
    Student data;
    struct no *next;
    struct no *previous
}No;

typedef No* List;

List* create_list();
void free_list(List* student_list);

int size_list(List* student_list);
int empty_list(List* studen_list);

#endif // LISTA_H_INCLUDED
