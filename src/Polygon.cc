#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"
#include <iostream>
double distance2(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

Polygon::Polygon(std::vector<Point> vertices /* clockwise */){
    this->vertices = vertices;
}

bool Polygon::ContainedBy(Circle &circle){
    for(auto i: this->vertices){
        if(distance2(i, circle.getCen()) >= circle.getRad()){
            return false;
        }
    }
    return true;
}
bool Polygon::ContainedBy(Polygon &polygon){
    for(auto k : vertices){
        auto j = polygon.getVer().end() - 1;
        bool oddEdges= false;
        for (auto i = polygon.getVer().begin(); i != polygon.getVer().end(); i++) {
            if ( (i->y < k.y && j->y >= k.y) ||  (j->y < k.y && i->y >= k.y) ) {
                if (i->x + (k.y-i->y)/(j->y - i->y)*(j->x - i->x) < k.x) {
                    oddEdges=!oddEdges; 
                }
            }
            j=i;
        }//http://alienryderflex.com/polygon/
    
        if(!oddEdges){
            return false;
        }
    }
    return true;
}
bool Polygon::ContainedBy(ReuleauxTriangle &rt){
    for(auto k : vertices){
        double maxDist = 0;
        for(int i = 0; i < 3; i++){
            if(distance2(rt.getVer()[i], k) > maxDist){
                maxDist = distance2(rt.getVer()[i], k);
            }
        } 
        if(maxDist >= rt.getRad()){
            return false;
        }
    }
    return true;
}

std::vector<Point> Polygon::getVer(){
    return this->vertices;
}

void Polygon::print(){
    for(auto i: vertices){
        std::cerr << "(" << i.x << "," << i.y << ")" << std::endl;
    }
}