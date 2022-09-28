#include "fireball.h"

FireBall::FireBall(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);


    inverseMass_=1/100;
    angle_=angle;
    float velocity=4000;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle_)),velocity*qSin(qDegreesToRadians(angle_)),0);

    damping_ = 0.5;
    *gravity = Vector3D(0,-5,0);
    type_=LASER;

    radius_=1.0;
}

void FireBall::display(){

    //Pushing the current world matrix in the stack
    glPushMatrix();
    //When position vector added, correct this line and uncomment
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
