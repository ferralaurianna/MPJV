#ifndef BOX_H
#define BOX_H

#include "primitives.h"

class Box : public Primitives
{
public:
    Box(Vector3D halfSize=Vector3D(),Matrix localPosition=Matrix(4,new float[16]{0,0,0,0,
                                                                                 0,0,0,0,
                                                                                 0,0,0,0,
                                                                                 0,0,0,1}));

    Vector3D halfSize_;
};

#endif // BOX_H
