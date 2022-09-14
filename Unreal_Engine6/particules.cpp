#include "particules.h"

Particules::Particules(float posX,float posY,float posZ,float radius,float inverseMass,float initialVelocity,float angle,ProjectileType type)
{
    position_=new Vector3D(posX,posY,posZ);

    radius_=radius;
    inverseMass_=inverseMass;
    angle_=angle;
    initialVelocity_=new Vector3D(initialVelocity*qCos(qDegreesToRadians(angle_)),initialVelocity*qSin(qDegreesToRadians(angle_)),0);
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

void Particules::integrer(float temps){
    (*position_)=(*initialVelocity_)*temps+(*gravity)*0.5*qPow(temps,2);
}
