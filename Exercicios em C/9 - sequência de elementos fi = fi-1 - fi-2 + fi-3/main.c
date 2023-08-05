#include <stdio.h>
#include <stdlib.h>

int sequence_elements(int position){
    if(position > 3){
        int elements[position];

        elements[0] = 0;
        elements[1] = 1;
        elements[2] = 1;

        for(int i = 3; i < position; i++){
            elements[i] = elements[i-1] - elements[i-2] + elements[i-3];
        }

        return elements[position-1];
    }
    else if(position == 1){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    int position = 10;
    int elemento = sequence_elements(position);

    printf("position: %d e element: %d\n", position, elemento);
    return 0;
}
