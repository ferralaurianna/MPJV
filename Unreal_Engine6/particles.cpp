#include "particles.h"
#include <iostream>

using namespace std;

Particles::Particles(float posX,float posY,float posZ,float radius,float inverseMass,float velocity,float damping,float angle,ProjectileType type)
{
    position_=new Vector3D(posX,posY,posZ);

    radius_=radius;
    inverseMass_=inverseMass;
    angle_=angle;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);
    damping_=damping;
    type_=type;
}

void Particles::display(){

    //Pushing the current world matrix in the stack
    glPushMatrix();

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

void Particles::integrer(float duration){

    if(!hasReachedGround)
    {
        //Update of the current velocity
        (*velocity_)=(*velocity_)*qPow(damping_,duration)+(*gravity)*duration;

        //Udpate of the current position
        (*position_)=(*position_)+(*velocity_)*duration;

        cout<<"velocity: x="<<(*velocity_).getX()<<"|y="<<(*velocity_).getY()<<"|z="<<(*velocity_).getZ()<<endl;
        cout<<"position: x="<<(*position_).getX()<<"|y="<<(*position_).getY()<<"|z="<<(*position_).getZ()<<endl;

        if(position_->getY()<0){
            position_->setY(0);
            hasReachedGround = true;
        }
    }

}
