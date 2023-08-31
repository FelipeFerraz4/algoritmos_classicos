#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX_SIZE_LIST 100

typedef struct sequentialList {
    int size_list;
    int list_int[MAX_SIZE_LIST];
} SequentialList;

SequentialList* create_list();
void free_list(SequentialList* list_int);

int insertElement(SequentialList* list_int, int data);
#endif // LISTA_H_INCLUDED
