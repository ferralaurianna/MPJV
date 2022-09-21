#ifndef PARTICULES_H
#define PARTICULES_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <GL/glu.h>
#include <Vector3D.h>
#include <QtMath>

enum ProjectileType {BALL,CANONBALL,LASER,FIREBALL};
Vector3D *gravity = new Vector3D(0,-9.8,0);

class Particules
{
public:
    //Constructor (do not forget to add the x,y and z position at the beggining of the constructor)
    Particules(float posX=0,float posY=0,float posZ=0,float radius=1,float inverseMass=1,float velocity=1,float angle_=45,ProjectileType type=BALL);

    //Render method
    void display();

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

    float radius_;
    float inverseMass_;
    Vector3D *velocity_;
    float angle_;
    ProjectileType type_;

    //Euler integrer
    void integrer(float temps);

};

#endif // PARTICULES_H