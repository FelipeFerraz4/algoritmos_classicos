#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct no{
    int  info;
    struct no* next;
} No;

typedef struct pilha{
    int size_stack;
    No* topo;
} Stack;

Stack create_Stack(void);
void free_stack(Stack* pilha);

int push(Stack* pilha, int dado);
int pop(Stack* pilha);

void print_stack(Stack pilha);
#endif // STACK_H_INCLUDED
