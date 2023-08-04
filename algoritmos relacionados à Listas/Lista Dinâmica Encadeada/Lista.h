#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct student{
    int id;
    char name[30];
    float test[3];
}Student;

typedef struct no{
    Student data;
    struct no* next;
}No;

typedef No* List;

List* create_list();
void free_list(List* student_list);
int size_list(List* student_list);
int empty_list(List* student_list);

#endif // LISTA_H_INCLUDED
