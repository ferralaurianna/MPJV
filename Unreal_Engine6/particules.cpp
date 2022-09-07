#include "particules.h"

Particules::Particules(float radius,float inverseMass,float initialVelocity,ProjectileType type)
{
    radius_=radius;
    inverseMass_=inverseMass;
    initialVelocity_=initialVelocity;
    type_=type;
}

void Particules::display(){

    //Pushing the current world matrix in the stack
    glPushMatrix();
    //When position vector added, correct this line and uncomment
    //glTranslatef(positionX,positionY,positionZ);

    //Drawing of the particule
    GLUquadric *quadric=gluNewQuadric();
    gluQuadricDrawStyle(quadric,GLU_FILL);

    gluSphere(quadric,radius_,50,50);

    //Getting back memory after the drawing
    gluDeleteQuadric(quadric);

    //Getting back the world matrix before the translation from the stack
    glPopMatrix();

}
