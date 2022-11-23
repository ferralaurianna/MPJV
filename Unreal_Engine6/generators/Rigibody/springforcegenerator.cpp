#include "springforcegenerator.h"

SpringForceGenerator::SpringForceGenerator(Vector3D bodyAnchor, Rigidbody* otherRigidbody,
                                           Vector3D otherBodyAnchor, float k, float restLenght)
{
    bodyAnchor_=bodyAnchor;
    otherRigidbody_=otherRigidbody;
    otherBodyAnchor_=otherBodyAnchor;
    k_=k;
    restLenght_=restLenght;
}

SpringForceGenerator::~SpringForceGenerator(){
    delete otherRigidbody_;
}

void SpringForceGenerator::updateForce(Rigidbody* rigidbody,float duration){
    //TODO: Prendre les body anchor comme relatives aux rigidbody
    Vector3D difference = bodyAnchor_+(*rigidbody->getPosition())-otherBodyAnchor_-(*otherRigidbody_->getPosition());
    float l = difference.norm();
    Vector3D force = difference.normalize()*((l-restLenght_)*k_);
    //TODO: Ajouter les forces au bon pt d'application
    rigidbody->addForcesAtBodyPoint(force,bodyAnchor_);
}
