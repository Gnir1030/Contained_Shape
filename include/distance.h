#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#include "Point.h"
#include <math.h>

double distance(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

#endif