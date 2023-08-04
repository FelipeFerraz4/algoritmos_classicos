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
void free_list(List* list_student);

#endif // LISTA_H_INCLUDED
