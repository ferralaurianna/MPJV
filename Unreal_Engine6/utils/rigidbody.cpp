#include "rigidbody.h"

Rigidbody::Rigidbody(float posX=0,float posY=0,float posZ=0,float radius=1,float mass=1,float velocity=1,Quaternion * orientation=new Quaternion(),Vector3D * rotation=new Vector3D()) {

    position_ = new Vector3D(posX,posY,posZ);
    radius_ = radius;
    inverseMass_ = float(1)/mass;
    velocity_ = new Vector3D(velocity*qCos(qDegreesToRadians(orientation)),velocity*qSin(qDegreesToRadians(orientation)),0);
    orientation_ = orientation;
    rotation_ = rotation;

};

Rigidbody::~Rigidbody() {
    delete orientation_;
    delete rotation_;
}

void Rigidbody::display() {
    // TODO je ne sais pas faire d'OpenGL :(
    ((Particles *) this)->display();
}

void Rigidbody::integrate(float duration) {

    ((Particles *) this)->integrer(duration);

    // Updates the orientation
    // Pas opti, recréation de la variable à chaque frame, bofbof
    Quaternion * omega = new Quaternion(0, rotation_->getX(), rotation_->getY(), rotation_->getZ());
    (*orientation_)=(*orientation_) + (duration/2)*(*omega)*(*orientation_);

    // Update angular velocity
    Vector3D * angularAcc = new Vector3D(); // Todo with angular momentum
    (*rotation_)=(*rotation_)+(*angularAcc)*duration;

}

void Rigidbody::calculateDerivedData() {

    // TODO compute the transform matrix

    // Normalizes the orientation
    *orientation_->normalize();

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
    ((Particles *) this)->clearAccum();
    *accumTorque_ = Vector3D(0,0,0);
}
