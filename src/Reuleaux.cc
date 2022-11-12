<<<<<<< Updated upstream
#include "Reuleaux.h"

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3] /* clockwise */){

}

bool ReuleauxTriangle::ContainedBy(Circle &circle){
    return true;
}
bool ReuleauxTriangle::ContainedBy(Polygon &polygon){
    return true;
}
bool ReuleauxTriangle::ContainedBy(ReuleauxTriangle &rt){
    return true;
}
