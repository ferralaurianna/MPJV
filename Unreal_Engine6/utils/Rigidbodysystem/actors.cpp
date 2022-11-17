#include "actors.h"

Actors::Actors(Rigidbody rigidbody, std::vector<Polygone> polygones, int id, bool gravity)
{
    rigidbody_ = rigidbody;
    polygones_ = polygones;
    id_ = id;
    hasGravity_ = gravity;
}
