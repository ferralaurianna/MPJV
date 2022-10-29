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
    Pos.push_back(posx + side/2);
    Pos.push_back(posy + side/2);
    Pos.push_back(posz + side/2);

    //2nd vertex
    Pos.push_back(posx + side/2);
    Pos.push_back(posy + side/2);
    Pos.push_back(posz - side/2);

    //3rd vertex
    Pos.push_back(posx - side/2);
    Pos.push_back(posy + side/2);
    Pos.push_back(posz - side/2);

    //4th vertex
    Pos.push_back(posx - side/2);
    Pos.push_back(posy + side/2);
    Pos.push_back(posz + side/2);

    //5th vertex
    Pos.push_back(posx + side/2);
    Pos.push_back(posy - side/2);
    Pos.push_back(posz + side/2);

    //6th vertex
    Pos.push_back(posx + side/2);
    Pos.push_back(posy - side/2);
    Pos.push_back(posz - side/2);

    //7th vertex
    Pos.push_back(posx - side/2);
    Pos.push_back(posy - side/2);
    Pos.push_back(posz - side/2);

    //8th vertex
    Pos.push_back(posx - side/2);
    Pos.push_back(posy - side/2);
    Pos.push_back(posz + side/2);
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
    //glNormal3f(0,2/3,-1/3);
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx + side/2, posy - side/2, posz - side/2);
    glVertex3f(posx - side/2, posy - side/2, posz - side/2);

    //face droite
    //glNormal3f(-1/3,2/3,0);
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx - side/2, posy - side/2, posz + side/2);
    glVertex3f(posx - side/2, posy - side/2, posz - side/2);

    //face gauche
    //glNormal3f(1/3,2/3,0);
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx + side/2, posy - side/2, posz + side/2);
    glVertex3f(posx + side/2, posy - side/2, posz - side/2);

    //face derrière
    //glNormal3f(0,2/3,1/3);
    glVertex3f(posx, posy + side/2, posz);
    glVertex3f(posx + side/2, posy - side/2, posz + side/2);
    glVertex3f(posx - side/2, posy - side/2, posz + side/2);

    glEnd();
}
