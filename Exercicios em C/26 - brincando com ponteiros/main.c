#include <stdio.h>
#include <stdlib.h>



int main()
{
    int x = 10;
    int *p;
    p = &x;

    printf("x = %d\n", x);
    printf("&x = %p\n", &x);
    printf("valor do p = %d\n", *p);
    printf("Endereco do p = %p\n", p);
    printf("Endereco de p = %p\n", &p);


    int y;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    x -=1;
    (*p) += x;
    printf("y = %d\n", y);

    return 0;
}
