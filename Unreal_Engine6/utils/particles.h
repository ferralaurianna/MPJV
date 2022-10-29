#ifndef PARTICLES_H
#define PARTICLES_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <GL/glu.h>
#include "Vector3D.h"
#include <QtMath>

class Particles
{
public:
    /**
     * @brief Particles
     * posX, posY, posZ, radius, mass, velocity angle
     * The constructor of the Particles class , with many physical variables as parameters.
     */
    Particles(float posX=0,float posY=0,float posZ=0,float radius=1,float mass=1,float velocity=1,float angle_=45);
    ~Particles();

    //Render method
    virtual void display();


    //Euler integrer
    void integrer(float temps);

    //Getters/setters
    float getInverseMass(){return inverseMass_;};
    void setInverseMass(float inverseMass){inverseMass_=inverseMass;};
    float getRadius(){return radius_;};
    Vector3D* getInitialVelocity(){return velocity_;};
    void setVelocity(Vector3D *initialVelocity){velocity_=initialVelocity;};

    //Add here the getter/setter of the position vector
    Vector3D* getPosition(){return position_;};
    void setPosition(Vector3D *position){position_=position;};
    bool isOnGround(){return hasReachedGround;}

    void addForces(Vector3D force);
    void clearAccum();


protected:

    //Initialize the gravity, damping and type of Particles (protected to have access in derived class)
    float damping_ = 0;
    Vector3D *accumForce_ = new Vector3D(0,0,0);

    //Add here a position handmade vector
    Vector3D *position_;
    Vector3D *velocity_;

    float inverseMass_;

    float radius_;

    bool hasReachedGround=false;

};

#endif // PARTICLES_H
