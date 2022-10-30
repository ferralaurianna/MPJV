#include "Plateforme.h"

Plateforme::Plateforme()
{
}

Plateforme::Plateforme(float _width, float _length, float _height, float _posx, float _posy, float _posz)
{
    widthx = _width;
    lengthz = _length;
    heighty = _height;
    posx = _posx;
    posy = _posy;
    posz = _posz;

    //1st vertex
    Vector3D Topleftback = Vector3D(posx + widthx/2, posy + heighty/2,posz + lengthz/2);

    //2nd vertex
    Vector3D Topleftfront = Vector3D(posx + widthx/2, posy + heighty/2,posz - lengthz/2);

    //3rd vertex
    Vector3D Toprightfront = Vector3D(posx - widthx/2, posy + heighty/2,posz - lengthz/2);

    //4th vertex
    Vector3D Toprightback = Vector3D(posx - widthx/2, posy + heighty/2,posz + lengthz/2);

    //5th vertex
    Vector3D Botleftback = Vector3D(posx + widthx/2, posy - heighty/2,posz + lengthz/2);

    //6th vertex
    Vector3D Botleftfront = Vector3D(posx + widthx/2, posy - heighty/2,posz - lengthz/2);

    //7th vertex
    Vector3D Botrightfront = Vector3D(posx - widthx/2, posy - heighty/2,posz - lengthz/2);

    //8th vertex
    Vector3D Botrightback = Vector3D(posx - widthx/2, posy - heighty/2,posz + lengthz/2);

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

Plateforme::~Plateforme()
{
}

void Plateforme::Display() const
{

    glBegin(GL_QUADS);

    // face arrière
    glColor3ub(0,255,0);
    glNormal3f(0,0,1);
    glVertex3f(posx + widthx/2, posy + heighty/2, posz + lengthz/2);
    glVertex3f(posx + widthx/2, posy - heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy - heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy + heighty/2, posz + lengthz/2);

    //face avant
    glNormal3f(0,0,-1);
    glVertex3f(posx + widthx/2, posy + heighty/2, posz - lengthz/2);
    glVertex3f(posx + widthx/2, posy - heighty/2, posz - lengthz/2);
    glVertex3f(posx - widthx/2, posy - heighty/2, posz - lengthz/2);
    glVertex3f(posx - widthx/2, posy + heighty/2, posz - lengthz/2);

    //face droite
    glNormal3f(1,0,0);
    glVertex3f(posx - widthx/2, posy - heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy + heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy + heighty/2, posz - lengthz/2);
    glVertex3f(posx - widthx/2, posy - heighty/2, posz - lengthz/2);

    //face gauche
    glNormal3f(-1,0,0);
    glVertex3f(posx + widthx/2, posy - heighty/2, posz + lengthz/2);
    glVertex3f(posx + widthx/2, posy + heighty/2, posz + lengthz/2);
    glVertex3f(posx + widthx/2, posy + heighty/2, posz - lengthz/2);
    glVertex3f(posx + widthx/2, posy - heighty/2, posz - lengthz/2);


    //face dessus
    glNormal3f(0,1,0);
    glVertex3f(posx + widthx/2, posy + heighty/2, posz - lengthz/2);
    glVertex3f(posx + widthx/2, posy + heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy + heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy + heighty/2, posz - lengthz/2);

    //face dessous
    glNormal3f(0,-1,0);
    glVertex3f(posx + widthx/2, posy - heighty/2, posz - lengthz/2);
    glVertex3f(posx + widthx/2, posy - heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy - heighty/2, posz + lengthz/2);
    glVertex3f(posx - widthx/2, posy - heighty/2, posz - lengthz/2);

    glEnd();
}
