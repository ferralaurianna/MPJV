#include "frameupdate.h"
#include <iostream>

using namespace std;

// Constructor
frameupdate::frameupdate()
{
    deltatime = 100;
}

// Destructor
frameupdate::~frameupdate()
{}

// Setters
void frameupdate::Setdt(float dt)
{
    deltatime = dt;
}

void frameupdate::MainLoop()
{
    connect(this->timer, SIGNAL(timeout()), this, SLOT(UpdateFrame()));
    timer->start(deltatime);
}

// Update the position and speed of the particle
void frameupdate::UpdateFrame(QVector3D position, QVector3D speed, QVector3D acceleration)
{

    QVector3D newpos = position + speed * deltatime + 0.5 * acceleration * deltatime * deltatime ;
    QVector3D newspeed = speed + acceleration * deltatime;
    position = newpos;
    speed = newspeed;
}
