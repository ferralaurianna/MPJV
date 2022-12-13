#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "utils/matrix.h"
#include "utils/Vector3D.h"

class Primitives
{
public:
    Primitives();

    typedef enum  {
            UNDEFINED = 0,
            SPHERE = 1,
            PLANE = 2,
            BOX = 3
        } TYPE;

    Matrix localPosition_=Matrix(4,new float[16]{0,0,0,0,
                                                 0,0,0,0,
                                                 0,0,0,0,
                                                 0,0,0,1});
    TYPE type=TYPE::UNDEFINED;

    float radiusOroffset_ = 0;
    Vector3D normalOrhalfsize = Vector3D(0,0,0);
};

#endif // PRIMITIVES_H
