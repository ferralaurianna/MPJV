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
    Pos.push_back(posx + widthx/2);
    Pos.push_back(posy + heighty/2);
    Pos.push_back(posz + lengthz/2);

    //2nd vertex
    Pos.push_back(posx + widthx/2);
    Pos.push_back(posy + heighty/2);
    Pos.push_back(posz - lengthz/2);

    //3rd vertex
    Pos.push_back(posx - widthx/2);
    Pos.push_back(posy + heighty/2);
    Pos.push_back(posz - lengthz/2);

    //4th vertex
    Pos.push_back(posx - widthx/2);
    Pos.push_back(posy + heighty/2);
    Pos.push_back(posz + lengthz/2);

    //5th vertex
    Pos.push_back(posx + widthx/2);
    Pos.push_back(posy - heighty/2);
    Pos.push_back(posz + lengthz/2);

    //6th vertex
    Pos.push_back(posx + widthx/2);
    Pos.push_back(posy - heighty/2);
    Pos.push_back(posz - lengthz/2);

    //7th vertex
    Pos.push_back(posx - widthx/2);
    Pos.push_back(posy - heighty/2);
    Pos.push_back(posz - lengthz/2);

    //8th vertex
    Pos.push_back(posx - widthx/2);
    Pos.push_back(posy + heighty/2);
    Pos.push_back(posz + lengthz/2);
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
