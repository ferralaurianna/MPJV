#ifndef BOUNDINGVOLUME_H
#define BOUNDINGVOLUME_H
#include "utils/RigidBodySystem/actors.h"

// Structure of a Point
struct Point {
    int x;
    int y;
    int z;

    Point():
        x(-1), y(-1), z(-1){
    }
    Point(int a, int b, int c):
        x(a), y(b), z(c){
    }
};

class BoundingVolume
{
private:
    Point center;
    float radius;

public:
    BoundingVolume(Actors actor);

    Point getCenter() const {return center;}

    bool intersectWithBox(int xTopLeftFront, int yTopLeftFront, int zTopLeftFront, int xBottomRightBack, int yBottomRightBack, int zBottomRightBack);

};

#endif // BOUNDINGVOLUME_H
