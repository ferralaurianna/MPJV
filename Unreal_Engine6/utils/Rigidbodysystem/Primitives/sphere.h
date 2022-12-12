#ifndef SPHERE_H
#define SPHERE_H

#include "primitives.h"

class Sphere : public Primitives
{
public:
    Sphere(float radius=0,Matrix localPosition=Matrix(4,new float[16]{0,0,0,0,
                                                                      0,0,0,0,
                                                                      0,0,0,0,
                                                                      0,0,0,1}));

    float radius_;
    TYPE type=TYPE::SPHERE;

    float getPropFloat(){return radius_;};
};

#endif // SPHERE_H
