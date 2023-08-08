#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main()
{
    //printf("Hello World!");
    //int user_number;

    Point duck;
    duck = create_point(4, 6, 'd');

    printf("Coordenada X = %d\n", duck.coordinateX);
    printf("Coordenada Y = %d\n", duck.coordinateY);

    Point fish = create_point(4, 0, 'f');
    Point bread = create_point(0, 6, 'b');

    float result1 = distance_between_points(duck, fish);
    float result2 = distance_between_points(duck, bread);

    printf("Distancia para o peixe = %.2f\n", result1);
    printf("Distancia para o pao = %.2f\n", result2);

    Line line_duck_fish = create_Line(duck, fish);
    Line line_duck_bread = {duck, bread};


    return 0;
}
