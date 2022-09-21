#include "particules.h"

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
    //Update of the current velocity
    (*velocity_)=(*velocity_)+(*gravity)*duration;

    //Udpate of the current position
    (*position_)=(*position_)*(*velocity_)*duration+(*gravity)*0.5*qPow(duration,2);
}
