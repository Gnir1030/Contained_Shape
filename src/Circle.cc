#include "Circle.h"
#include <cmath>

double distance(Point& p1, Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

    // do not modify or remove this constructor
Circle::Circle(const Point &center, double radius){
    this->center = center;
    this->radius = radius;
}

    // do not modify or remove these functions
bool Circle::ContainedBy(Circle &circle){
    double dist = distance(this->center, circle.center);
    if(dist + this->radius >= circle.radius){
        return false;
    }
    return true;
}
bool ContainedBy(Polygon &polygon){
    return true;
}

bool ContainedBy(ReuleauxTriangle &rt){
    return true;
}