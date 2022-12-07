#include "physicsystem.h"


PhysicSystem::PhysicSystem()
{
    forces_ = ForceRegistreryRigidbody();
    movedThisframe_ = std::vector<int>();
    possibleCollisions_ = std::vector<int[2]>();
    collisions_ = collisionRegistreryRigidody ();
    narrowPhase = NarrowPhaseDetector(&collisions_,&possibleCollisions_);
}

void PhysicSystem::addSimpleForce(Rigidbody* rb,int id, int idForce, Vector3D bodyAnchor)
{
    if(idForce == -1)
    {
        forces_.add(rb,new GravityForceGenerator(),id,-1);
    }

    if(idForce == -3)
    {
        forces_.add(rb,new InputForceGenerator(bodyAnchor),id,-3);
    }
}

void PhysicSystem::addForcesBetween(int id, int idOther, int idForce,
                                    Rigidbody* rb,Vector3D bodyAnchor,
                                    Rigidbody* otherRigidbody, Vector3D otherBodyAnchor,
                                    float k, float restLenght)
{
    if(idForce == 1)
    {
        forces_.add(rb,new SpringForceGenerator(bodyAnchor,otherRigidbody,otherBodyAnchor,k,restLenght),id,idOther);
    }
}

void PhysicSystem::removeForce(int id, int idOther)
{
    forces_.remove(id,idOther);
}

void PhysicSystem::removeForces(int id)
{
    forces_.removeAll(id);
}

void PhysicSystem::UpdateForces(float duration)
{
    forces_.updateForces(duration);
}

void PhysicSystem::handleCollisions(float duration)
{
    collisions_.handleCollisions(duration);
}

void PhysicSystem::addToCollision(Actors* actor)
{
    //add the object into the octree (just the Rigidbody*)
    //Octree.add(actor)
    narrowPhase.addActor(actor);
}

void PhysicSystem::removeCollisions(int id)
{
    //remove the object from the octree, it will not collide with anything
    //Octree.remove(id);
    narrowPhase.removeActor(id);
}
