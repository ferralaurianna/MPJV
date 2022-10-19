#include "laser.h"

// Override of the Particle constructor with the laser physical features
Laser::Laser(float posX,float posY,float posZ,float angle)
{
    position_=new Vector3D(posX,posY,posZ);


    inverseMass_=1/0.0001;
    float velocity=10000;
    velocity_=new Vector3D(velocity*qCos(qDegreesToRadians(angle)),velocity*qSin(qDegreesToRadians(angle)),0);
    angle_ = angle;

    damping_ = 1;
    *accumForce_ = Vector3D();

    radius_=0.5;
}

// Override of the Particule display method with the laser appaerance
void Laser::display(){

    //Pushing the current world matrix in the stack
    glPushMatrix();

    glTranslatef(position_->getX(),position_->getY(),position_->getZ());

    GLfloat colorAmbient_tab[] = {0.5f,0.f,0.f,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
    GLfloat colorDiffuse_tab[] = {1.f,0.f,0.f,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {0.774597,0.774597,0.774597,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8f);

    //Drawing of the particle
    GLUquadric *quadric=gluNewQuadric();
    gluQuadricDrawStyle(quadric,GLU_FILL);

    glRotated(angle_,1.f,0.f,0.f);

    gluCylinder(quadric,radius_,radius_,5.0,50,50);

    //Getting back memory after the drawing
    gluDeleteQuadric(quadric);

    //Getting back the world matrix before the translation from the stack
    glPopMatrix();

}
