#ifndef PARTICULES_H
#define PARTICULES_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <GL/glu.h>
#include <Vector3D.h>
#include <QtMath>

enum ProjectileType {BALL,CANONBALL,LASER,FIREBALL};

class Particules
{
public:
    //Constructor (do not forget to add the x,y and z position at the beggining of the constructor)
    Particules(float posX=0,float posY=0,float posZ=0,float radius=1,float inverseMass=1,float velocity=1,float damping=1,float angle_=45,ProjectileType type=BALL);

    //Render method
    void display();


    //Euler integrer
    void integrer(float temps);

    //Getters/setters
    float getInverseMass(){return inverseMass_;};
    void setInverseMass(float inverseMass){inverseMass_=inverseMass;};

    Vector3D* getInitialVelocity(){return velocity_;};
    void setVelocity(Vector3D *initialVelocity){velocity_=initialVelocity;};

    ProjectileType getType(){return type_;};
    void setType(ProjectileType type){type_=type;};

    //Add here the getter/setter of the position vector
    Vector3D* getPosition(){return position_;};
    void setPosition(Vector3D *position){position_=position;};

private:
    //Add here a position handmade vector
    Vector3D *position_;
    Vector3D *velocity_;
    Vector3D *gravity = new Vector3D(0,-5000.0,0);

    float inverseMass_;
    float damping_;

    float radius_;
    float angle_;
    ProjectileType type_;

    bool hasReachedGround=false;

};

#endif // PARTICULES_H
