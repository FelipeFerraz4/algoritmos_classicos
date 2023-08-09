#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main()
{
    Heap *spacecraft_heap;
    spacecraft_heap = create_heap();

    Person person1 = {1, "Julha", 30, "Gliese"};
    Person person2 = {2, "Marta", 47, "Kepler"};
    Person person3 = {3, "Ana", 10, "Kepler"};
    Person person4 = {4, "Marcos", 19, "Gliese"};
    Person person5 = {5, "Rafa", 26, "Gliese"};
    
    Resources product1 = {6, "Banana", 100};
    Resources product2 = {7, "Water", 10000};
    Resources product3 = {8, "Meat", 100};
    Resources product4 = {9, "Fish", 100};
    Resources product5 = {10, "Milk", 100};
    
    free_heap(spacecraft_heap);
    printf("Hello world!\n");
    return 0;
}
