#include <stdio.h>
#include <math.h>
typedef struct{
    double x;
    double y;
}Point;
void printPoint(Point p){
    printf("Tasko kordinates: (%.2f, %.2f) ", p.x, p.y);
}
Point createPoint(double x, double y){
    Point newPoint = {x,y};
    return newPoint;
}
double getDistance(Point a, Point b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}
int main(){
    printf("Atstumas: %.2f",getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0)));
}
