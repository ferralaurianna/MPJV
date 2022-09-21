#include "particules.h"
#include <iostream>

using namespace std;

Particules::Particules(float posX,float posY,float posZ,float radius,float inverseMass,float velocity,float angle,ProjectileType type)
{
    position_=new Vector3D(posX,posY,posZ);

    radius_=radius;
    inverseMass_=inverseMass;
    angle_=angle;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);
    type_=type;
}

void Particules::display(){

    //Pushing the current world matrix in the stack
    glPushMatrix();
    //When position vector added, correct this line and uncomment
    glTranslatef(position_->getX(),position_->getY(),position_->getZ());

    //Drawing of the particule
    GLUquadric *quadric=gluNewQuadric();
    gluQuadricDrawStyle(quadric,GLU_FILL);

    gluSphere(quadric,radius_,50,50);

    //Getting back memory after the drawing
    gluDeleteQuadric(quadric);

    //Getting back the world matrix before the translation from the stack
    glPopMatrix();

}

void Particules::integrer(float duration){

    if(!hasReachedGround)
    {
        //Update of the current velocity
        (*velocity_)=(*velocity_)+(*gravity)*duration;

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
