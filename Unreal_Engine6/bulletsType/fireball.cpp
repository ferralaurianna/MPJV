#include "fireball.h"

// Override of the Particle constructor with the fireball's physical features
FireBall::FireBall(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);


    inverseMass_=1;
    float velocity=2000;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle)),velocity*qSin(qDegreesToRadians(angle)),0);
    angle_ = angle;

    damping_ = 0.3;
    *accumForce_ = Vector3D(0,-11000,0);

    radius_=1.0;
}

// Override of the Particule display method with the fireball's appaerance
void FireBall::display(){

    //Pushing the current world matrix in the stack
    glPushMatrix();

    glTranslatef(position_->getX(),position_->getY(),position_->getZ());

    GLfloat colorAmbient_tab[] = {0.5f,0.5f,0.f,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
    GLfloat colorDiffuse_tab[] = {1.f,1.f,0.f,1.0};
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

void FireBall::CheckCollision()
{
    if(position_->getY()<0)
    {
        clearAccum();
        hasReachedGround=true;
        velocity_->setX(0);velocity_->setY(0);velocity_->setZ(0);
        position_->setY(0);
    }
}
