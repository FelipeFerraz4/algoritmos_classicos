#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#define SIZE_DEFAULT 30
#define CAPACITY_PASSENGERS 10
#define CAPACITY_PRODUCT 20

typedef struct person{
    int id;
    char name[30];
    int age;
    char planet[30];
}Person;

typedef struct resources{
    int id;
    char name[30];
    int quantity;
} Resources;

typedef struct spacecraft{
    int spacecraft_id;
    Person passengers[CAPACITY_PASSENGERS];
    Resources product[CAPACITY_PRODUCT];
}Spacecraft;

typedef struct no{
    int priority;
    Spacecraft spacecraft;
    struct no *left_child;
    struct no *right_child;
}No;

typedef struct heap{
    int size_heap;
    No *root;
}Heap;

Heap* create_heap();
void free_no(No *root);
void free_heap(Heap *heap);

#endif // HEAP_H_INCLUDED
