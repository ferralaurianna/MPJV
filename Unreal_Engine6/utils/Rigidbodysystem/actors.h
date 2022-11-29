#ifndef ACTORS_H
#define ACTORS_H


#include "utils/polygon.h"
#include "utils/Rigidbodysystem/rigidbody.h"
#include "utils/Rigidbodysystem/Primitives/primitives.h"
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

    /**
     * @brief Actors
     * @param rigidbody : the rigidbody to be used for this actor
     * @param polygones : a vector of polygones representing the visual appearence of the object
     * @param id : the id of the actor
     * @param gravity : wether gravity should be activated for this actor
     * @param primitives : a vector of primitives representing the combined hitboxed of the object
     * The constructor of the Actors class, which store an ID, a rigidbody, wheter it is affected by gravity and lists of the actors it is linked to.
     */
    Actors(Rigidbody rigidbody, std::vector<Polygone> polygones, int id, bool gravity = true,std::vector<Primitives> primitives);

    std::vector<Polygone>* getPolygones(){return &polygones_;};

    std::vector<Primitives>* getPrimitives(){return &primitives_;};

    Rigidbody* getRigidbody(){return &rigidbody_;};

    /**
     * @brief addLink
     * @param id : the id of the actor attached
     * @param idOther : the id of the actor to wich the link is attached to
     * A function used to add a registered one-way spring link to an actor, does not add the link to the physic system.
     */
// WARNING : Never use manually !
    void addLink(int idOther, Vector3D anchor, Vector3D otherAnchor){linksTo_.push_back({idOther,anchor,otherAnchor});}
    /**
     * @brief addCable
     * @param id : the id of the actor attached
     * @param idOther : the id of the actor to wich the cable is attached to
     * A function used to add a registered one-way cable to an actor, does not add the cable to the physic system.
     */
// WARNING : Never use manually !
    void addCable(int idOther, Vector3D anchor, Vector3D otherAnchor){cablesTo_.push_back({idOther,anchor,otherAnchor});}

    void setGrav(bool grav){hasGravity_ = grav;};

    int getId(){return id_;};

    bool getGrav(){return hasGravity_;};

    std::vector<Connection>* getLinks(){return &linksTo_;};

    std::vector<Connection>* getCables(){return &cablesTo_;};

    /**
     * @brief addCabel
     * @param id : the id of the actor attached
     * @param idOther : the id of the actor to wich the cable is attached to
     * A function used to remove a registered one-way spring link to an actor, does not remove the cable from the physic system.
     */
    void removeLink(int id, int idOther);

    /**
     * @brief addCabel
     * @param id : the id of the actor attached
     * @param idOther : the id of the actor to wich the cable is attached to
     * A function used to remove a registered one-way cable to an actor, does not remove the cable from the physic system.
     */
    void removeCable(int id, int idOther);

protected:
    std::vector<Polygone> polygones_;

    std::vector<Primitives> primitives_;

    Rigidbody rigidbody_;

    int id_;

    /**
     * @brief linksTo_
     * The list of actors it this one is attached to by a one-way spring link.
     */
    std::vector<Connection> linksTo_= std::vector<Connection>();
    /**
     * @brief cablesTo_
     * The list of actors it this one is attached to by a one-way cable.
     */
    std::vector<Connection> cablesTo_= std::vector<Connection>();

    bool hasGravity_;
};

#endif // ACTORS_H
