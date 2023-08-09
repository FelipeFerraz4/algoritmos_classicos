#define MAX_NAME 30;
#define MAX_SYMPTOMS 70

typedef struct people{
    int id;
    char name[MAX_NAME];
    char symptoms[MAX_SYMPTOMS];
}People

typedef struct no{
    int priority;
    People people;
}No;

typedef struct heap{
    int size_heap;
    No **root;
}Heap;
