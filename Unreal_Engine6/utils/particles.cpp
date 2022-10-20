#include "particles.h"
#include <iostream>

using namespace std;

Particles::Particles(float posX,float posY,float posZ,float radius,float mass,float velocity,float angle)
{
    position_=new Vector3D(posX,posY,posZ);

    radius_=radius;
    inverseMass_=1/mass;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle)),velocity*qSin(qDegreesToRadians(angle)),0);

}

Particles::~Particles()
{
    delete position_;
    delete velocity_;
    delete accumForce_;
}

void Particles::display()
{

    //Pushing the current world matrix in the stack
    glPushMatrix();
    //When position vector added, correct this line and uncomment
    glTranslatef(position_->getX(),position_->getY(),position_->getZ());

    GLfloat colorAmbient_tab[] = {0.5f,0.25f,0.f,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
    GLfloat colorDiffuse_tab[] = {1.f,0.5f,0.f,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {0.774597,0.774597,0.774597,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8f);

    //Drawing of the particle
    GLUquadric *quadric=gluNewQuadric();
    gluQuadricDrawStyle(quadric,GLU_FILL);

    gluSphere(quadric,radius_,50,50);

    //Getting back memory after the drawing
    gluDeleteQuadric(quadric);

    //Getting back the world matrix before the translation from the stack
    glPopMatrix();

}

// Euler integration linked to the particule
void Particles::integrer(float duration){

    if(!hasReachedGround)
    {
        //Update of the current velocity
        (*velocity_)=(*velocity_)*qPow(damping_,duration)+(*accumForce_*inverseMass_)*duration;

        //Udpate of the current position
        (*position_)=(*position_)+(*velocity_)*duration;

        //Manage the ground collision in the 0Z plan
        if(position_->getY()<0){
            hasReachedGround = true;
        }
    }
}

void Particles::addForces(Vector3D force)
{
    *accumForce_ = (*accumForce_)+(force);
}

void Particles::clearAccum()
{
    *accumForce_ = Vector3D(0,0,0);
}
