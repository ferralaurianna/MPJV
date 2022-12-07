#include "actors.h"
#include <algorithm>

Actors::Actors(Rigidbody rigidbody, std::vector<Polygone> polygones, int id, bool gravity, std::vector<Primitives> primitives, bool collisions)
{
    rigidbody_ = rigidbody;
    polygones_ = polygones;
    id_ = id;
    hasGravity_ = gravity;
    primitives_ = primitives;
    hasCollisions_ = collisions;
}

void Actors::removeLink(int id, int idOther)
{
    std::vector<Connection>::iterator it;
    it = std::find(linksTo_.begin(), linksTo_.end(), idOther) ;
    if(it != linksTo_.end())
    {
        linksTo_.erase(it);
    }
}

void Actors::removeCable(int id, int idOther)
{
    std::vector<Connection>::iterator it;
    it = std::find(cablesTo_.begin(), cablesTo_.end(), idOther);
    if(it != cablesTo_.end())
    {
        cablesTo_.erase(it);
    }
}
