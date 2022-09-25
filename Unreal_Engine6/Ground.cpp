#include "Ground.h"

Ground::Ground()
{
    random = new QRandomGenerator();
    quadrique = gluNewQuadric();
    posRoad=0;
    posCiel=0;
    posTarget=-random->bounded(200);
}

void Ground::sendTextures(GLuint* text)
{
    textures = text;
}

Ground::~Ground()
{
    gluDeleteQuadric(quadrique);
}

void Ground::Display() const
{
    glPushMatrix();

    GLfloat colorAmbientH_tab[] = {0.25,0.25,0.25,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientH_tab);
    GLfloat colorDiffuseH_tab[] = {0.5,0.5,0.5,0.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseH_tab);
    GLfloat colorSpecularH_tab[] = {0.0,0.0,0.0,0.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularH_tab);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,textures[0]);

    glBegin(GL_QUADS);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2f(0+posRoad,0);glVertex3f(4000.0f,0.0f,-500.0f);
    glTexCoord2f(0+posRoad,100);glVertex3f(-4000.0f,0.0f,-500.0f);
    glTexCoord2f(100+posRoad,100);glVertex3f(-4000.0f,0.0f,3500.0f);
    glTexCoord2f(100+posRoad,0);glVertex3f(4000.0f,0.0f,3500.0f);

    glEnd();

    GLfloat colorAmbientS_tab[] = {0.5,0.5,0.5,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientS_tab);
    GLfloat colorDiffuseS_tab[] = {0.9,0.9,0.9,0.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseS_tab);
    GLfloat colorSpecularS_tab[] = {0.0,0.0,0.0,0.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularS_tab);

    glBindTexture(GL_TEXTURE_2D,textures[1]);

    glBegin(GL_QUADS);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2f(0+posCiel,0);glVertex3f(6160.0f,4239.0f,3500.0f);
    glTexCoord2f(0+posCiel,1);glVertex3f(6160.0f,-1.0f,3500.0f);
    glTexCoord2f(1+posCiel,1);glVertex3f(-6160.0f,-1.0f,3500.0f);
    glTexCoord2f(1+posCiel,0);glVertex3f(-6160.0f,4239.0f,3500.0f);

    glEnd();

    glTranslated(posTarget,0.01f,0.f);
    glRotated(90.f,1.f,0.f,0.f);

    gluQuadricTexture(quadrique,GLU_TRUE);

    GLfloat colorAmbientR_tab[] = {0.5,0.25,0.25,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientR_tab);
    GLfloat colorDiffuseR_tab[] = {1.0,0.5,0.5,0.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseR_tab);
    GLfloat colorSpecularR_tab[] = {0.0,0.0,0.0,0.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularR_tab);

    glBindTexture(GL_TEXTURE_2D,textures[2]);

    gluDisk(quadrique,0,10,50,50);

    GLfloat colorAmbientB_tab[] = {0.5,0.5,0.5,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientB_tab);
    GLfloat colorDiffuseB_tab[] = {0.9,0.9,0.9,0.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseB_tab);
    GLfloat colorSpecularB_tab[] = {0.0,0.0,0.0,0.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularB_tab);

    glBindTexture(GL_TEXTURE_2D,textures[2]);

    gluDisk(quadrique,10,20,50,50);

    GLfloat colorAmbientBl_tab[] = {0.25,0.25,0.5,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientBl_tab);
    GLfloat colorDiffuseBl_tab[] = {0.5,0.5,1.0,0.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseBl_tab);
    GLfloat colorSpecularBl_tab[] = {0.0,0.0,0.0,0.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularBl_tab);

    glBindTexture(GL_TEXTURE_2D,textures[2]);

    gluDisk(quadrique,20,30,50,50);

    gluQuadricTexture(quadrique,GLU_FALSE);

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void Ground::slideSky()
{
    if(posCiel<2)
    {
        posCiel += 0.0001;
    }
    else
    {
        posCiel =  0.0001;
    }
}

void Ground::moveTarget()
{
    posTarget=-random->bounded(200);
}
