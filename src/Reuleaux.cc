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

    int j = 2;
    double minDist = distance3(circle.getCen(), vertices[0]); 
    Point minP = vertices[0];
    for(int i  = 0; i < 3; i++){
        std::cerr << minP.x << " " << minP.y << std::endl;
        int neg = 1;
        if(vertices[i].x < vertices[j].x){ neg = -1; }
        if(neg * (vertices[i].x - vertices[j].x) * circle.getCen().y > neg*((vertices[i].y - vertices[j].y) * circle.getCen().x + (vertices[i].x * vertices[j].y - vertices[i].y * vertices[j].x))){
            return true;
        }
        double dist = distance3(circle.getCen(), vertices[i]);
        if(minDist > dist){minDist = dist; minP = vertices[i];}
        j = i;
    }

    if(distance3(circle.getCen(),minP) + radius >= circle.getRad()){
        return false;
    }

    return true;
    //return Circle(minPoint, radius).ContainedBy(circle);
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
    }
    return true;
}

Point* ReuleauxTriangle::getVer(){
    return vertices;
}

double ReuleauxTriangle::getRad(){
    return radius;
}