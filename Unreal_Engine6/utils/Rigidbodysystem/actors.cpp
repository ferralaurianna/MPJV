#include "actors.h"
#include <algorithm>

Actors::Actors(Rigidbody rigidbody, std::vector<Polygone> polygones, int id, bool gravity)
{
    rigidbody_ = rigidbody;
    polygones_ = polygones;
    id_ = id;
    hasGravity_ = gravity;
}

void Actors::removeLink(int id, int idOther)
{
    vector<Connection>::iterator it;
    it = std::find_if(linksTo_.begin(), linksTo_.end(), it->idOther == idOther);
    if(it != linksTo_.end())
    {
        linksTo_.erase(it);
    }
}

void Actors::removeCable(int id, int idOther)
{
    vector<Connection>::iterator it;
    it = std::find_if(cablesTo_.begin(), cablesTo_.end(), it->idOther == idOther);
    if(it != cablesTo_.end())
    {
        cablesTo_.erase(it);
    }
}
