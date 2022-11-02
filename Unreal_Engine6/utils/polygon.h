#ifndef POLYGON_H
#define POLYGON_H

#include "utils/Vector3D.h"

struct Polygone{
    Vector3D s0;
    Vector3D s1;
    Vector3D s2;
    Vector3D s3;

    Polygone(Vector3D s1, Vector3D s2, Vector3D s3, Vector3D s4) :
        s0(s1), s1(s2), s2(s3), s3(s4) {};
};

#endif // POLYGON_H
