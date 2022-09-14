#ifndef PARTICULES_H
#define PARTICULES_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <GL/glu.h>
#include <Vector3D.h>

enum ProjectileType {BALL,CANONBALL,LASER,FIREBALL};

class Particules
{
public:
    //Constructor (do not forget to add the x,y and z position at the beggining of the constructor)
    Particules(float posX=0,float posY=0,float posZ=0,float radius=1,float inverseMass=1,float initialVelocity=1,ProjectileType type=BALL);

    //Render method
    void display();

    //Getters/setters
    float getInverseMass(){return inverseMass_;};
    void setInverseMass(float inverseMass){inverseMass_=inverseMass;};

    float getInitialVelocity(){return initialVelocity_;};
    void setInitialVelocity(float initialVelocity){initialVelocity_=initialVelocity;};

    ProjectileType getType(){return type_;};
    void setType(ProjectileType type){type_=type;};

    //Add here the getter/setter of the position vector

private:
    //Add here a position handmade vector
    Vector3D *position_;

    float radius_;
    float inverseMass_;
    float initialVelocity_;
    ProjectileType type_;

};

#endif // PARTICULES_H
