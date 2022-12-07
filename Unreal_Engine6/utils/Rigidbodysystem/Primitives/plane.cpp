#include "plane.h"

Plane::Plane(Vector3D normal,Matrix localPosition,float offset)
{
        normal_=normal;
        localPosition_=localPosition;
        offset_=offset;
}
