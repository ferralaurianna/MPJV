#include "rigidbody.h"
#include <QtMath>

Rigidbody::Rigidbody(float posX,float posY,float posZ,float mass,Quaternion * orientation) {

    position_ = new Vector3D(posX,posY,posZ);
    inverseMass_ = float(1)/mass;
    velocity_ = new Vector3D(0,0,0);
    orientation_ = orientation;
};

Rigidbody::~Rigidbody() {
    delete orientation_;
    delete angularVelocity_;
    delete position_;
    delete velocity_;
}

void Rigidbody::integrate(float duration) {

    //Update of the current velocity
    (*velocity_)=(*velocity_)*qPow(damping_,duration)+(*accumForce_*inverseMass_)*duration;

    // Update angular velocity
    (*angularVelocity_)=(*angularVelocity_)*qPow(damping_,duration)+(*accumTorque_)*duration;


    //Udpate of the current position
    (*position_)=(*position_)+(*velocity_)*duration;

    // Updates the orientation
    orientation_->UpdateByAngularVelocity(*angularVelocity_,duration);

}

void Rigidbody::calculateDerivedData() {

    // TODO compute the transform matrix

    // Normalizes the orientation
    orientation_->Normalized();

}

void Rigidbody::addForces(Vector3D force)
{
    *accumForce_ = (*accumForce_)+(force);
}

void Rigidbody::addForcesAtWorldPoint(Vector3D force, Vector3D point)
{
    // TODO
    *accumForce_ = (*accumForce_)+(force);
}

void Rigidbody::addForcesAtBodyPoint(Vector3D force, Vector3D point)
{
    // TODO
    *accumForce_ = (*accumForce_)+(force);
}


void Rigidbody::clearAccum()
{
    *accumForce_ = Vector3D(0,0,0);
    *accumTorque_ = Vector3D(0,0,0);
}
