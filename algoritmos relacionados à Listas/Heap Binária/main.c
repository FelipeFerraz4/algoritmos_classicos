#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main()
{
    Heap *spacecraft_heap;
    spacecraft_heap = create_heap();

    free_heap(spacecraft_heap);
    printf("Hello world!\n");
    return 0;
}
