#ifndef ACTORLIST_H
#define ACTORLIST_H

#include "utils/Rigidbodysystem/actors.h"
#include "utils/Rigidbodysystem/physicsystem.h"
#include <vector>

class ActorList
{
public:
    /**
     * @brief ActorList
     * The constructor of the ActorList class, wich record all the actors in the scene.
     */
    ActorList(); 
    /**
     * @brief setPhysic
     * @param physic : a pointer to the physic system
     * A function used to pass the physic system to be used in the scene.
     */
    void setPhysic(PhysicSystem* physic){physic_=physic;};
    /**
     * @brief addActor
     * @param actor : the actor to be added
     * A function used to add an actor to the list.
     */
    void addActor(Actors actor);
    /**
     * @brief removeActor
     * @param id : the id of the actor to do the operation on
     * A function used to remove an actor from the list.
     */
    void removeActor(int id);
    /**
     * @brief removeGravity
     * @param id : the id of the actor to do the operation on
     * A function used deactivate gravity for an actor.
     */
    void removeGravity(int id);
    /**
     * @brief addGravity
     * @param id : the id of the actor to do the operation on
     * A function used activate gravity for an actor.
     */
    void addGravity(int id);
    /**
     * @brief addLink
     * @param id : the id of the actor to do the operation on
     * @param idOther : the id of the actor to wich the link is attached
     * @param bodyAnchor : the local position of the attaching point on the rigidbody
     * @param otherBodyAnchor : the local position of the attaching point on the other rigidbody.
     * A function used to attach a one-way spring from an actor to another
     */
    void addLink(int id, int idOther,Vector3D bodyAnchor = Vector3D(0,0,0), Vector3D otherBodyAnchor = Vector3D(0,0,0));
    /**
     * @brief removeLink
     * @param id : the id of the actor to do the operation on
     * @param id : the id of the actor to do the operation on
     * A function used to remove a one-way spring from an actor to another.
     */
    void removeLink(int id, int idOther);
    /**
     * @brief addCable
     * @param id : the id of the actor to do the operation on
     * @param idOther : the id of the actor to wich the cable is attached
     * @param bodyAnchor : the local position of the attaching point on the rigidbody
     * @param otherBodyAnchor : the local position of the attaching point on the other rigidbody.
     * A function used to attach a one-way cable from an actor to another
     */
    void addCable(int id, int idOther,Vector3D bodyAnchor = Vector3D(0,0,0), Vector3D otherBodyAnchor = Vector3D(0,0,0));
    /**
     * @brief removeCable
     * @param id : the id of the actor to do the operation on
     * @param id : the id of the actor to do the operation on
     * A function used to remove a one-way cable from an actor to another.
     */
    void removeCable(int id, int idOther);
    /**
     * @brief getActor
     * @param id : the id of the actor to do the operation on
     * A function used to get a pointer to an Actor in the scene.
     */
    Actors* getActor(int id);
    /**
     * @brief clearForces
     * A function used to clear the force buffer of the rigidbody of all actors.
     */
    void clearForces();
    /**
     * @brief integrateAll
     * @param duration : the duration of the logic frame
     * A function used to integrate the physic on all the actors in the scene.
     */
    void integrateAll(float duration);
    /**
     * @brief setPhysic
     * A function used to pass the physic system to be used in the scene.
     */
    int size() {return list.size();};

    void removecollisions(int id);

    void addCollisions(int id);


private:
    std::vector<Actors> list;

    PhysicSystem* physic_;


};

#endif // ACTORLIST_H
