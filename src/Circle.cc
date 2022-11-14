#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"
//#include <cmath>

/*
double distance(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
*/

    // do not modify or remove this constructor
Circle::Circle(const Point &center, double radius){
    this->center = center;
    this->radius = radius;
}

    // do not modify or remove these functions
bool Circle::ContainedBy(Circle &circle){
    double dist = distance(this->center, circle.getCen());
    if(dist + this->radius >= circle.getRad()){
        return false;
    }
    return true;
}


bool Circle::ContainedBy(Polygon &polygon){
    auto j = polygon.getVer().end() - 1;
    bool oddEdges= false;
    //bool bigRad = false; 
    double Dist;
    for (auto i = polygon.getVer().begin(); i != polygon.getVer().end(); i++) {
        if ((i->y < center.y && j->y >= center.y) ||  (j->y < center.y && i->y >= center.y )) {
            if (i->x + (center.y-i->y)/(j->y - i->y)*(j->x - i->x) < center.x) {
                oddEdges=!oddEdges; 
            }
        }

        Dist = std::abs((j->x - i->x) * center.y + (i->y - j->y) * center.x + (i->x * j->y - j->x * i->y))/sqrt(pow(i->y - j->y, 2) + pow(j->x - i->x, 2));
        if(Dist <= radius){
            //bigRad = Dist <= radius;
            double a = i->y - j->y, b = j->x - i->x, c = i->x * j->y - i->y * j->x;
            double p = b *b/(a*a + b*b)*center.x - a*b/(a*a + b*b)*center.y - a*c/(a*a + b*b);
            if((p <= i->x && p >= j->x) || (p >= i->x && p <= j->x))
                return false;
        }
        j=i;
    }
    
    if(!oddEdges){
        return false;
    }
    //if(bigRad){
    //    return false;
    //}
    return true;
}

bool Circle::ContainedBy(ReuleauxTriangle &rt){
    double maxDist = 0;
    for(int i = 0; i < 3; i++){
        if(distance(rt.getVer()[i], center) > maxDist){
            maxDist = distance(rt.getVer()[i], center);
        }
    } 
    if(maxDist + radius >= rt.getRad()){
        return false;
    }
    return true;
}


Point Circle::getCen(){
    return this->center;
}

double Circle::getRad(){
    return this->radius;
}