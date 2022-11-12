#include "Polygon.h"

Polygon::Polygon(std::vector<Point> vertices /* clockwise */){

}

bool Polygon::ContainedBy(Circle &circle){
    return true;
}
bool Polygon::ContainedBy(Polygon &polygon){
    return true;
}
bool Polygon::ContainedBy(ReuleauxTriangle &rt){
    return true;
}