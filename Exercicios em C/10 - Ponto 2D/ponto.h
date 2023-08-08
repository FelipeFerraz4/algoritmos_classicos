#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

typedef struct point{
    float coordinateX, coordinateY;
    char symbol;
} Point;

Point create_point(float coordinateX, float coordinateY, char symbol);
float distance_between_points(Point Point1, Point Point2);

#endif // PONTO_H_INCLUDED
