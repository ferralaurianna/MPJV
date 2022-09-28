#include "scene1/ground.h"

Ground::Ground()
{
    random = new QRandomGenerator();
    quadrique = gluNewQuadric();
    posSky=0;
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
    //Pushing the current world matrix in the stack
    glPushMatrix();

    //Creating the ground material
    GLfloat colorAmbientH_tab[] = {0.25,0.25,0.25,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientH_tab);
    GLfloat colorDiffuseH_tab[] = {0.5,0.5,0.5,0.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseH_tab);
    GLfloat colorSpecularH_tab[] = {0.0,0.0,0.0,0.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularH_tab);

    //Using the texture
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,textures[0]);

    //Drawing the ground with its norm of light reflection
    glBegin(GL_QUADS);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2f(0,0);glVertex3f(4000.0f,0.0f,-500.0f);
    glTexCoord2f(0,100);glVertex3f(-4000.0f,0.0f,-500.0f);
    glTexCoord2f(100,100);glVertex3f(-4000.0f,0.0f,3500.0f);
    glTexCoord2f(100,0);glVertex3f(4000.0f,0.0f,3500.0f);

    glEnd();

    //Creating the sky material
    GLfloat colorAmbientS_tab[] = {0.5,0.5,0.5,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientS_tab);
    GLfloat colorDiffuseS_tab[] = {0.9,0.9,0.9,0.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseS_tab);
    GLfloat colorSpecularS_tab[] = {0.0,0.0,0.0,0.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularS_tab);

    //Using the texture
    glBindTexture(GL_TEXTURE_2D,textures[1]);

    //Drawing the sky with its norm of light reflection
    glBegin(GL_QUADS);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2f(0+posSky,0);glVertex3f(6160.0f,4239.0f,3500.0f);
    glTexCoord2f(0+posSky,1);glVertex3f(6160.0f,-1.0f,3500.0f);
    glTexCoord2f(1+posSky,1);glVertex3f(-6160.0f,-1.0f,3500.0f);
    glTexCoord2f(1+posSky,0);glVertex3f(-6160.0f,4239.0f,3500.0f);

    glEnd();

    //Drawing the target
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

    //Getting back the world matrix before the translation from the stack
    glPopMatrix();
}

// Manage the animation of the sky
void Ground::slideSky()
{
    if(posSky<2)
    {
        posSky += 0.0001;
    }
    else
    {
        posSky =  0.0001;
    }
}

// Manage the movement of the target
void Ground::moveTarget()
{
    posTarget=-random->bounded(200);
}
