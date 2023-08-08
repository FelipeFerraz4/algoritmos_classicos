#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

typedef struct point{
    int coordinateX, coordinateY;
    char symbol;
} Point;

typedef struct line{
    Point point1;
    Point point2;
}Line;

typedef struct plane{
    int size_plene;
    Point point[3];
}Plane;

Point create_point(int coordinateX, int coordinateY, char symbol);
Line create_Line(Point point1, Point point2);
float distance_between_points(Point Point1, Point Point2);

#endif // PONTO_H_INCLUDED
