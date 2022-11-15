#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"
#include<algorithm> 
#include <iostream>

double distance3(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3] /* clockwise */){
    std::copy(vertices, vertices+3,this->vertices);
    this->radius = distance3(vertices[0], vertices[1]);
}

bool ReuleauxTriangle::ContainedBy(Circle &circle){
    for(int i = 0; i < 3; i++){
        if(distance3(vertices[i], circle.getCen()) >= circle.getRad()){
            return false;
        }
    }
    double minDist = distance3(vertices[0], circle.getCen());
    Point minPoint = vertices[0];
    if(minDist > distance3(vertices[1], circle.getCen())){
        minDist = distance3(vertices[1], circle.getCen());
        minPoint = vertices[1];
    }
    if(minDist > distance3(vertices[2], circle.getCen())){
        minDist = distance3(vertices[2], circle.getCen());
        minPoint = vertices[2];
    }

    return Circle(minPoint, radius).ContainedBy(circle);
}
bool ReuleauxTriangle::ContainedBy(Polygon &polygon){
    for(auto k : vertices){
        auto j = *(polygon.getVer().end() - 1);
        bool oddEdges= false;
        for (auto i : polygon.getVer()) {
            if ((i.y < k.y && j.y >= k.y) ||  (j.y < k.y && i.y >= k.y )) {
                if (i.x + (k.y-i.y)/(j.y - i.y)*(j.x - i.x) < k.x) {
                    oddEdges=!oddEdges; 
                }
            }
            j=i;
        }
    
        if(!oddEdges){
            return false;
        }
    }
/*
    auto j = *(polygon.getVer().end() - 1);
    for (auto i : polygon.getVer()) {
        double maxDist = 0;
        for(auto k : vertices){
            double Dist = std::abs((j.x - i.x) * k.y + (i.y - j.y) * k.x + (i.x * j.y - j.x * i.y))/sqrt(pow(i.y - j.y, 2) + pow(j.x - i.x, 2));
            if(maxDist < Dist){
                maxDist = Dist;
            }
        }
        if(maxDist >= radius){
            return false;
        }
        j = i;
    }
    */

    return true;
}
bool ReuleauxTriangle::ContainedBy(ReuleauxTriangle &rt){
    for(auto k : vertices){
        double maxDist = 0;
        for(int i = 0; i < 3; i++){
            if(distance3(rt.getVer()[i], k) > maxDist){
                maxDist = distance3(rt.getVer()[i], k);
            }
        } 
        if(maxDist >= rt.getRad()){
            return false;
        }
        double minDist = distance3(vertices[0], k);
        Point minPoint = vertices[0];
        if(minDist > distance3(vertices[1], k)){
            minDist = distance3(vertices[1], k);
            minPoint = vertices[1];
        }
        if(minDist > distance3(vertices[2], k)){
            minDist = distance3(vertices[2], k);
            minPoint = vertices[2];
        }
        if(minDist + radius >= rt.getRad())
            return false;
    }
    return true;
}

Point* ReuleauxTriangle::getVer(){
    return vertices;
}

double ReuleauxTriangle::getRad(){
    return radius;
}