#ifndef ACTORS_H
#define ACTORS_H


#include "utils/polygon.h"
#include "utils/Rigidbodysystem/rigidbody.h"
#include <vector>
class Actors
{
public:
    struct Connection
    {
        int idOther;
        Vector3D bodyAnchor_;
        Vector3D otherBodyAnchor_;

        bool operator ==(const int& y) {
            return idOther == y;
        }
    };

    bool operator ==(const int& y) {
        return id_  == y;
    }

    Actors();

    Actors(Rigidbody rigidbody, std::vector<Polygone> polygones, int id, bool gravity = true);

    std::vector<Polygone>* getPolygones(){return &polygones_;};

    Rigidbody* getRigidbody(){return &rigidbody_;};

// WARNING : use manually for init only !
    void addLink(int idOther, Vector3D anchor, Vector3D otherAnchor){linksTo_.push_back({idOther,anchor,otherAnchor});}
// WARNING : use manually for init only !
    void addCable(int idOther, Vector3D anchor, Vector3D otherAnchor){cablesTo_.push_back({idOther,anchor,otherAnchor});}

    void setGrav(bool grav){hasGravity_ = grav;};

    int getId(){return id_;};

    bool getGrav(){return hasGravity_;};

    std::vector<Connection>* getLinks(){return &linksTo_;};

    std::vector<Connection>* getCables(){return &cablesTo_;};

    void removeLink(int id, int idOther);

    void removeCable(int id, int idOther);

protected:
    std::vector<Polygone> polygones_;

    Rigidbody rigidbody_;

    int id_;

    std::vector<Connection> linksTo_= std::vector<Connection>();

    std::vector<Connection> cablesTo_= std::vector<Connection>();

    bool hasGravity_;
};

#endif // ACTORS_H
