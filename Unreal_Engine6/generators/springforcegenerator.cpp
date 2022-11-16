#include "springforcegenerator.h"

SpringForceGenerator::SpringForceGenerator(Vector3D* bodyAnchor,Rigidbody* otherRigidbody,
                                           Vector3D* otherBodyAnchor,float k, float restLenght)
{
    bodyAnchor_=bodyAnchor;
    otherRigidbody_=otherRigidbody;
    otherBodyAnchor=otherBodyAnchor;
    k_=k;
    restLenght_=restLenght;
}

SpringForceGenerator::~SpringForceGenerator(){
    delete bodyAnchor_;
    delete otherBodyAnchor_;
    delete otherRigidbody_;
}

void SpringForceGenerator::updateForce(Rigidbody* rigidbody,float duration){
    Vector3D difference = (*bodyAnchor_)-(*otherBodyAnchor_);
    float l = difference.norm();
    Vector3D force = difference.normalize()*((l-restLenght_)*k_);
    rigidbody->addForces(force);
}
