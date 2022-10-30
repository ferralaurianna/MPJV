#include "spike.h"

Spike::Spike()
{
}

Spike::Spike(float _side, float _posx, float _posy, float _posz)
{
    side = _side;
    posx = _posx;
    posy = _posy;
    posz = _posz;

    //1st vertex
    Vector3D Topleftback = Vector3D(posx + side/2, posy + side/2,posz + side/2);

    //2nd vertex
    Vector3D Topleftfront = Vector3D(posx + side/2, posy + side/2,posz - side/2);

    //3rd vertex
    Vector3D Toprightfront = Vector3D(posx - side/2, posy + side/2,posz - side/2);

    //4th vertex
    Vector3D Toprightback = Vector3D(posx - side/2, posy + side/2,posz + side/2);

    //5th vertex
    Vector3D Botleftback = Vector3D(posx + side/2, posy - side/2,posz + side/2);

    //6th vertex
    Vector3D Botleftfront = Vector3D(posx + side/2, posy - side/2,posz - side/2);

    //7th vertex
    Vector3D Botrightfront = Vector3D(posx - side/2, posy - side/2,posz - side/2);

    //8th vertex
    Vector3D Botrightback = Vector3D(posx - side/2, posy - side/2,posz + side/2);

    Vector3D NormeTop = Vector3D(0,1,0);
    Vector3D NormeBot = Vector3D(0,-1,0);
    Vector3D NormeRight = Vector3D(-1,0,0);
    Vector3D NormeLeft = Vector3D(1,0,0);
    Vector3D NormeFront = Vector3D(0,0,-1);
    Vector3D NormeBack = Vector3D(0,0,1);

    Polygone Topface = Polygone(Topleftback, Topleftfront, Toprightfront, Toprightback, NormeTop);
    Polygone Botface = Polygone(Botleftback, Botleftfront, Botrightfront, Botrightback, NormeBot);
    Polygone Rightface = Polygone(Toprightback, Toprightfront, Botrightfront, Botrightback, NormeRight);
    Polygone Leftface = Polygone(Topleftback, Topleftfront, Botleftfront, Botleftback, NormeLeft);
    Polygone Frontface = Polygone(Topleftfront, Toprightfront, Botrightfront, Botleftfront, NormeFront);
    Polygone Backface = Polygone(Topleftback, Toprightback, Botrightback, Botleftback, NormeBack);

    polygones.push_back(Topface);
    polygones.push_back(Botface);
    polygones.push_back(Rightface);
    polygones.push_back(Leftface);
    polygones.push_back(Frontface);
    polygones.push_back(Backface);
 }

void Spike::Display() const
{

    glBegin(GL_QUADS);

    GLfloat colorAmbient_tab[] = {0.25, 0.25, 0.25,0.6};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
    GLfloat colorDiffuse_tab[] = {0.4, 0.4,	0.4, 0.6};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {0.774597, 0.774597, 0.774597,0.6};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.f);

    // base
    glNormal3f(0,-1,0);
    glVertex3f(posx + side/2, posy - side/2, posz + side/2);
    glVertex3f(posx + side/2, posy - side/2, posz - side/2);
    glVertex3f(posx - side/2, posy - side/2, posz - side/2);
    glVertex3f(posx - side/2, posy - side/2, posz + side/2);

    //face avant
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx + side/2, posy - side/2, posz - side/2);
    glVertex3f(posx - side/2, posy - side/2, posz - side/2);

    //face droite
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx - side/2, posy - side/2, posz + side/2);
    glVertex3f(posx - side/2, posy - side/2, posz - side/2);

    //face gauche
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx + side/2, posy - side/2, posz + side/2);
    glVertex3f(posx + side/2, posy - side/2, posz - side/2);

    //face derrière
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx + side/2, posy - side/2, posz + side/2);
    glVertex3f(posx - side/2, posy - side/2, posz + side/2);

    glEnd();
}
