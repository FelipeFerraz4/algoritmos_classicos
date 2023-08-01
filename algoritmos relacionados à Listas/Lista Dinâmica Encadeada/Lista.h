#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct student{
    int ID;
    char name[30];
    float test[3];
}Student;

typedef struct list_student{
    int size_list;
    int* first_element;
}List;


#endif // LISTA_H_INCLUDED
