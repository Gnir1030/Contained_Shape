#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

Polygon::Polygon(std::vector<Point> vertices /* clockwise */){
    this->vertices = vertices;
    double x = 0, y = 0;
    for(auto i : vertices){
        x += i.x;
        y += i.y;
    }
    x /= vertices.size();
    y /= vertices.size();
    this->center = Point(x, y);
}

bool Polygon::ContainedBy(Circle &circle){
    for(auto i: this->vertices){
        if(distance(i, circle.getCen()) >= circle.getRad()){
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
            if(distance(rt.getVer()[i], k) > maxDist){
                maxDist = distance(rt.getVer()[i], k);
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

Point Polygon::getCen(){
    return this->center;
}