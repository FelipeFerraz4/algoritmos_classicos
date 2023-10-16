#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX_PALAVRA 100

typedef struct no{
    char info[MAX_PALAVRA];
    struct no* next;
} No;

typedef struct pilha{
    No* topo;
} Stack;

Stack create_stack();
void free_stack(Stack* pilha);

int push(Stack* pilha, char dado[]);
void pop(Stack* pilha, char palavra[]);

void print_stack(Stack* pilha);
#endif // STACK_H_INCLUDED
