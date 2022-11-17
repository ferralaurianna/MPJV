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
