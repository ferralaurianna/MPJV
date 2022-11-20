#include "physicsystem.h"


PhysicSystem::PhysicSystem()
{
    forces_ = ForceRegistreryRigidbody();
}

void PhysicSystem::addSimpleForce(Rigidbody* rb,int id, int idOther, int idForce, Vector3D bodyAnchor)
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
