#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"
#include <iostream>
#include <cmath>
using namespace std;

double distance(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

    // do not modify or remove this constructor
Circle::Circle(const Point &center, double radius){
    this->center = center;
    this->radius = radius;
}

    // do not modify or remove these functions
bool Circle::ContainedBy(Circle &circle){
    double dist = distance(this->center, circle.getCen());
    cerr << dist << endl;
    if(dist + this->radius >= circle.getRad()){
        return false;
    }
    return true;
}


bool Circle::ContainedBy(Polygon &polygon){
    return true;
}

bool Circle::ContainedBy(ReuleauxTriangle &rt){
    return true;
}


Point Circle::getCen(){
    return this->center;
}

double Circle::getRad(){
    return this->radius;
}