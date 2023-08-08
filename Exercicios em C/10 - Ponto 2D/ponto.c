#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ponto.h"

Point create_point(float coordinateX, float coordinateY, char symbol){
    Point point;

    point.coordinateX = coordinateX;
    point.coordinateY = coordinateY;

    point.symbol = symbol;

    return point;
}

float distance_between_points(Point point1, Point point2){
    float distance;
    float coordX = pow(point1.coordinateX - point2.coordinateX, 2);
    float coordY = pow(point1.coordinateY - point2.coordinateY, 2);

    distance = sqrt( coordX + coordY );

    return distance;

}
