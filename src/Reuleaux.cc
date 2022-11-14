#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"
#include<algorithm> 

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3] /* clockwise */){
    std::copy(vertices, vertices+3,this->vertices);
    this->radius = distance(vertices[0], vertices[1]);
}

bool ReuleauxTriangle::ContainedBy(Circle &circle){
    for(int i = 0; i < 3; i++){
        if(distance(vertices[i], circle.getCen()) >= circle.getRad()){
            return false;
        }
    }
    return true;
}
bool ReuleauxTriangle::ContainedBy(Polygon &polygon){
    for(auto k : vertices){
        auto j = polygon.getVer().end() - 1;
        bool oddEdges= false;
        bool bigRad = false;
        double Dist;
        for (auto i = polygon.getVer().begin(); i != polygon.getVer().end(); i++) {
            if ((i->y < k.y && j->y >= k.y) ||  (j->y < k.y && i->y >= k.y )) {
                if (i->x + (k.y-i->y)/(j->y - i->y)*(j->x - i->x) < k.x) {
                    oddEdges=!oddEdges; 
                }
            }
            Dist = std::abs((j->x - i->x) * k.y + (i->y - j->y) * k.x + (i->x * j->y - j->x * i->y))/sqrt(pow(i->y - j->y, 2) + pow(j->x - i->x, 2));
            if(Dist <= radius && !bigRad){
                bigRad = Dist <= radius;
            }
            j=i;
        }
    
        if(!oddEdges){
            return false;
        }
        if(bigRad){
            return false;
        }
    }
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