#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main()
{
    //printf("Hello World!");
    //int user_number;

    Point duck;
    duck = create_point(4, 6, 'd');

    printf("Coordenada X = %.2f\n", duck.coordinateX);
    printf("Coordenada Y = %.2f\n", duck.coordinateY);

    Point fish = create_point(4, 0, 'f');
    Point bread = create_point(0, 6, 'b');

    float result1 = distance_between_points(duck, fish);
    float result2 = distance_between_points(duck, bread);

    printf("Distancia para o peixe = %.2f\n", result1);
    printf("Distancia para o pao = %.2f\n", result2);

    return 0;
}
