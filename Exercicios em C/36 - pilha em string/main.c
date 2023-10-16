#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    Stack pilha = create_stack();

    push(&pilha, "!");
    push(&pilha, "World");
    push(&pilha, "hello");

    print_stack(&pilha);

    char palavra[MAX_PALAVRA];
    pop(&pilha, palavra);
    printf("%s\n", palavra);

    print_stack(&pilha);

    free_stack(&pilha);
    printf("Hello world!\n");
    return 0;
}
