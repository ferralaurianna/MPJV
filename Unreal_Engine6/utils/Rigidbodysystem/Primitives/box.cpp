#include "box.h"

Box::Box(Vector3D halfSize,Matrix localPosition)
{
    halfSize_=halfSize;
    localPosition_=localPosition;
    normalOrhalfsize =halfSize_;
    type = TYPE::BOX;
}
