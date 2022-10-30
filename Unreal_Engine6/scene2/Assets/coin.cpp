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
   Vector3D Topleftback = Vector3D(posx + radius, posy + radius,posz + height/2);

   //2nd vertex
   Vector3D Topleftfront = Vector3D(posx + radius, posy + radius,posz - height/2);

   //3rd vertex
   Vector3D Toprightfront = Vector3D(posx - radius, posy + radius,posz - height/2);

   //4th vertex
   Vector3D Toprightback = Vector3D(posx - radius, posy + radius,posz - height/2);

   //5th vertex
   Vector3D Botleftback = Vector3D(posx + radius, posy - radius,posz + height/2);

   //6th vertex
   Vector3D Botleftfront = Vector3D(posx + radius, posy - radius,posz - height/2);

   //7th vertex
   Vector3D Botrightfront = Vector3D(posx - radius, posy - radius,posz - height/2);

   //8th vertex
   Vector3D Botrightback = Vector3D(posx - radius, posy - radius,posz - height/2);

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
