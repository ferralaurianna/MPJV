#ifndef ACTORS_H
#define ACTORS_H


#include "utils/polygon.h"
#include "utils/Rigidbodysystem/rigidbody.h"
#include <vector>
class Actors
{
public:
    Actors(Rigidbody rigidbody, std::vector<Polygone> polygones, int id, bool gravity = true);

    std::vector<Polygone>* getPolygones(){return &polygones_;};

    Rigidbody* getRigidbody(){return &rigidbody_;};

// WARNING : use manually for init only !
    void addLink(int link){linksTo_.push_back(link);}
// WARNING : use manually for init only !
    void addCable(int cable){cablesTo_.push_back(cable);}

protected:
    std::vector<Polygone> polygones_;

    Rigidbody rigidbody_;

    int id_;

    std::vector<int> linksTo_= std::vector<int>();

    std::vector<int> cablesTo_= std::vector<int>();

    bool hasGravity_;
};

#endif // ACTORS_H
