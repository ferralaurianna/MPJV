#include "cannonball.h"

Cannonball::Cannonball()
{
    damping_ = 10.0;
    *gravity = Vector3D(0,200.0,0);
    type_=CANNONBALL;
}
