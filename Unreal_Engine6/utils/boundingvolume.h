#ifndef BOUNDINGVOLUME_H
#define BOUNDINGVOLUME_H
#include "utils/RigidBodySystem/actors.h"

// Structure of a Point
struct Point {
    float x;
    float y;
    float z;

    Point():
        x(-1), y(-1), z(-1){
    }
    Point(float a, float b, float c):
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

    void setCenter(float x_, float y_, float z_);

    bool intersectWithBox(int xTopLeftFront, int yTopLeftFront, int zTopLeftFront, int xBottomRightBack, int yBottomRightBack, int zBottomRightBack);

};

#endif // BOUNDINGVOLUME_H
