#include "coin.h"

Coin::Coin()
{
   quad = gluNewQuadric();
}

Coin::Coin(float _radius, float _height, float _posx, float _posy, float _posz)
{
   quad = gluNewQuadric();
   radius = _radius;
   height = _height;
   posx = _posx;
   posy = _posy;
   posz = _posz;

   //1st vertex
   Pos.push_back(posx + radius);
   Pos.push_back(posy + radius);
   Pos.push_back(posz + height/2);

   //2nd vertex
   Pos.push_back(posx + radius);
   Pos.push_back(posy + radius);
   Pos.push_back(posz - height/2);

   //3rd vertex
   Pos.push_back(posx - radius);
   Pos.push_back(posy + radius);
   Pos.push_back(posz - height/2);

   //4th vertex
   Pos.push_back(posx - radius);
   Pos.push_back(posy + radius);
   Pos.push_back(posz + height/2);

   //5th vertex
   Pos.push_back(posx + radius);
   Pos.push_back(posy - radius);
   Pos.push_back(posz + height/2);

   //6th vertex
   Pos.push_back(posx + radius);
   Pos.push_back(posy - radius);
   Pos.push_back(posz - height/2);

   //7th vertex
   Pos.push_back(posx - radius);
   Pos.push_back(posy - radius);
   Pos.push_back(posz - height/2);

   //8th vertex
   Pos.push_back(posx - radius);
   Pos.push_back(posy - radius);
   Pos.push_back(posz + height/2);
}

Coin::~Coin()
{
    gluDeleteQuadric(quad);
}

void Coin::Display() const
{
    gluQuadricDrawStyle(quad,GLU_FILL);

    GLfloat colorAmbient_tab[] = {0.24725f,0.1995f,0.0745f,0.4};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
    GLfloat colorDiffuse_tab[] = {0.75164f,0.60648f,0.22648f,0.4};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {0.628281,0.555802,0.366065,0.4};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.f);

    glPushMatrix();
    glTranslatef(posx,posy,posz);
    gluCylinder(quad,radius,radius,height,20,20);

    glPopMatrix();
    glPushMatrix();
    glTranslatef(posx,posy,posz+height/2);
    gluDisk(quad,0,radius,20,20);

    glPopMatrix();
    glPushMatrix();
    glTranslatef(posx,posy,posz-height/2);
    gluDisk(quad,0,radius,20,20);


//    gluDeleteQuadric(quad);

//    glDisable(GL_LIGHTING);

}
