#include "Reuleaux.h"
#include<algorithm> 

double distance(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3] /* clockwise */){
    std::copy(vertices, vertices+3,this->vertices);
    this->radius = distance(vertices[0], vertices[1]);
}

bool ReuleauxTriangle::ContainedBy(Circle &circle){
    double maxDist = 0;
    for(int i = 0; i < 3; i++){
        if(distance(vertices[i], circle.getCen()) > maxDist){
            maxDist = distance(rt.getVer()[i], center);
        }
    } 
    if(maxDist + radius >= rt.getRad()){
        return false;
    }
    return true;
}
bool ReuleauxTriangle::ContainedBy(Polygon &polygon){
    return true;
}
bool ReuleauxTriangle::ContainedBy(ReuleauxTriangle &rt){
    return true;
}

Point* ReuleauxTriangle::getVer(){
    return vertices;
}

double ReuleauxTriangle::getRad(){
    return radius;
}