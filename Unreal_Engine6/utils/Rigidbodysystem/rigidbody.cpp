#include "rigidbody.h"
#include <QtMath>

Rigidbody::Rigidbody(float posX,float posY,float posZ,float mass,Quaternion * orientation,Matrix * inertia) {

    position_ = new Vector3D(posX,posY,posZ);
    inverseMass_ = float(1)/mass;
    velocity_ = new Vector3D(0,0,0);
    orientation_ = orientation;
    //TODO : replace inertia by the inverse
    inverseInertia_= inertia->Inverse();
};

Rigidbody::~Rigidbody() {
}

void Rigidbody::integrate(float duration) {

    //Update of the current velocity
    (*velocity_)=(*velocity_)*qPow(damping_,duration)+accumForce_*inverseMass_*duration;

    //Update of the angular velocity
    (*angularVelocity_)=(*angularVelocity_)*qPow(angularDamping_,duration)+accumTorque_*duration;


    //Udpate of the current position
    (*position_)=(*position_)+(*velocity_)*duration;

    //Update of the orientation
    orientation_->UpdateByAngularVelocity(*angularVelocity_,duration);

    //Update of the inertia
    calculateDerivedData();

    //Clear the force
    clearAccum();

}

void Rigidbody::calculateDerivedData() {

    // TODO compute the transform matrix
    Matrix * quat2Mat = new Matrix(3);
    quat2Mat->SetOrientation(*orientation_);
    std::vector<float> * tab = new std::vector<float>();
    for(int i=0;i<16;i++)
    {
      int line =(int)i/4;
      int col = i%4;
      if(col<3&&line<3)
      {
        tab->push_back((*quat2Mat)(line,col));
      }
      else if(col==3&&line<3)
      {
        tab->push_back((*position_)[line]);
      }
      else if(col<3&&line==3)
      {
        tab->push_back(0);
      }
      else { tab->push_back(1); }
    }
    transformMatrix_= Matrix(4,tab->data());

    Matrix inverseTransformMatrix = transformMatrix_.Inverse();
    inverseInertia_=(transformMatrix_*(inverseInertia_).To4()*inverseTransformMatrix).To3();
}

void Rigidbody::addForces(Vector3D force)
{
    accumForce_ = accumForce_+force;
}

void Rigidbody::addForcesAtWorldPoint(Vector3D force, Vector3D point)
{
    accumForce_ = accumForce_+force;
    accumTorque_ = accumTorque_+inverseInertia_*(((*position_)-point)^force);
}

void Rigidbody::addForcesAtBodyPoint(Vector3D force, Vector3D point)
{
    accumForce_ = accumForce_+(force);
    accumTorque_ = accumTorque_+inverseInertia_*(point^force);
}


void Rigidbody::clearAccum()
{
    accumForce_ = Vector3D(0,0,0);
    accumTorque_ = Vector3D(0,0,0);
}
