#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ponto.h"

Point create_point(int coordinateX, int coordinateY, char symbol){
    Point point;

    point.coordinateX = coordinateX;
    point.coordinateY = coordinateY;

    point.symbol = symbol;

    return point;
}

Line create_Line(Point point1, Point point2){
    Line line;

    line.point1.coordinateX = point1.coordinateX;
    line.point1.coordinateY = point1.coordinateY;
    line.point2.coordinateX = point2.coordinateX;
    line.point2.coordinateY = point2.coordinateY;

    return line;

}

float distance_between_points(Point point1, Point point2){
    float distance;
    float coordX = pow(point1.coordinateX - point2.coordinateX, 2);
    float coordY = pow(point1.coordinateY - point2.coordinateY, 2);

    distance = sqrt( coordX + coordY );

    return distance;

}
