#ifndef PLANE_H
#define PLANE_H

#include "primitives.h"

class Plane : public Primitives
{
public:
    Plane(Vector3D normal=Vector3D(),Matrix localPosition=Matrix(4,new float[16]{0,0,0,0,
                                                                                 0,0,0,0,
                                                                                 0,0,0,0,
                                                                                 0,0,0,1}), float offset=0);

    Vector3D normal_;
    float offset_;
};

#endif // PLANE_H
