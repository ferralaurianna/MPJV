#include "gun.h"

Gun::Gun()
{
    quadric = gluNewQuadric();
    posX_=200;
    posY_=0;
    posZ_=0;
    angY_=90;
    angGun_=0;
    elevation=10;
}

void Gun::sendTextures(GLuint* text)
{
    textures = text;
}

Gun::~Gun()
{
    gluDeleteQuadric(quadric);
}

void Gun::Display()
{
    glPushMatrix();

    glTranslated(posX_,posY_,posZ_);
    glRotated(angY_,0.f,1.f,0.f);

    Draw();

    glColor3ub(0,0,0);

    glPopMatrix();
}


void Gun::Draw()
{
    GLfloat colorAmbient_tab[] = {0.25,0.25,0.25,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
    GLfloat colorDiffuse_tab[] = {0.4,0.4,0.4,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {0.774597,0.774597,0.774597,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8f);

    glColor3ub(128,0,0);

    glPushMatrix();

    DrawSupport(0);
    DrawSupport(1);

    DrawMechanics(elevation,angGun_,0);
    DrawMechanics(elevation,angGun_,1);

    DrawGun(0,angGun_,elevation);

    glPopMatrix();
}

void Gun::DrawSupport(int direction)
{
    glPushMatrix();

    glRotated(180.f*direction,0.f,1.f,0.f);

    GLfloat colorAmbient_tabEngine[] = {0.1,0.1,0.1,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tabEngine);
    GLfloat colorDiffuse_tabEngine[] = {0.2,0.2,0.2,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tabEngine);
    GLfloat colorSpecular_tabEngine[] = {0.774597,0.774597,0.774597,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tabEngine);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8f);

    glEnable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_TRUE);

    glBindTexture(GL_TEXTURE_2D,textures[0]);

    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);

    DrawCube(2.5f,20.f,5.f,-0.5f,-20.f,-10.f);
    DrawCube(2.f,20.f,5.f,-0.5f,-20.f,-2.f);
    DrawCube(2.f,20.f,2.f,-0.5f,-20.f,-4.f);
    DrawCube(2.f,20.f,-3.f,-0.5f,-20.f,-2.f);

    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_FALSE);

    glPopMatrix();
}


void Gun::DrawGun(float recoil, float angleGun, float elevation)
{
    glPushMatrix();

    glTranslated(0.f,elevation,0.f);
    glRotated(angleGun,1.f,0.f,0.f);
    glTranslated(0.f,0.f,recoil);

    GLfloat colorAmbient_tabEngine[] = {0.1,0.1,0.1,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tabEngine);
    GLfloat colorDiffuse_tabEngine[] = {0.2,0.2,0.2,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tabEngine);
    GLfloat colorSpecular_tabEngine[] = {0.774597,0.774597,0.774597,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tabEngine);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8f);

    glEnable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_TRUE);

    glBindTexture(GL_TEXTURE_2D,textures[1]);

    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);

    DrawCube(1.2f,0.1f,2.f,-0.4f,-0.2f,-4.f);
    DrawCube(-0.8f,0.1f,2.f,-0.4f,-0.2f,-4.f);

    glTranslated(0.f,0.f,-13.f);
    gluCylinder(quadric,0.8f,1.f,20.01f,100,100);
    gluDisk(quadric,0.5f,0.8f,100,100);
    gluCylinder(quadric,0.5f,0.5f,19.01f,100,100);
    glTranslated(0.f,0.f,19.f);
    gluDisk(quadric,0.f,0.51f,100,100);
    glTranslated(0.f,0.f,1.f);
    gluDisk(quadric,0.f,1.01f,100,100);

    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_FALSE);

    glPopMatrix();
}

void Gun::DrawMechanics(float elevation, float angleGun, float direction)
{
    float dir = 1 - 2*direction;
    glPushMatrix();

    glTranslated(0.f,elevation,0.f);

    GLfloat colorAmbient_tab[] = {0.25,0.25,0.25,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
    GLfloat colorDiffuse_tab[] = {0.4,0.4,0.4,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {0.774597,0.774597,0.774597,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8f);

    glEnable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_TRUE);

    glBindTexture(GL_TEXTURE_2D,textures[0]);

    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);

    DrawCube(dir*1.5f,1.f,3.f,dir*-0.25f,-0.9f,-6.f);
    DrawCube(dir*1.5f,0.1f,-2.1f,dir*-0.25f,-6.f,-0.9f);

    DrawCube(dir*1.5f,0.1f,-1.8f,dir*-0.25f,-0.2f,-0.1f);
    DrawCube(dir*1.5f,-0.1f,-1.8f,dir*-0.25f,-0.1f,-0.3f);

    glTranslated(0.f,0.f,-2.f);

    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_FALSE);

    glPopMatrix();

    glPushMatrix();

    glTranslated(0.f,elevation,0.f);
    glRotated(angleGun,1.f,0.f,0.f);

    GLfloat colorAmbient_tab2[] = {0.25,0.25,0.25,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab2);
    GLfloat colorDiffuse_tab2[] = {0.4,0.4,0.4,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab2);
    GLfloat colorSpecular_tab2[] = {0.774597,0.774597,0.774597,1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab2);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8f);

    glEnable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_TRUE);

    glBindTexture(GL_TEXTURE_2D,textures[1]);

    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);

    DrawCube(dir*1.25f,0.2f,6.1f,dir*-0.05f,-0.4f,-8.2f);
    DrawCube(dir*1.2f,0.2f,6.1f,dir*-0.2f,-0.1f,-8.2f);
    DrawCube(dir*1.2f,-0.1f,6.1f,dir*-0.2f,-0.1f,-8.2f);
    DrawCube(dir*1.2f,0.1f,6.1f,dir*-0.2f,-0.2f,-0.1f);
    DrawCube(dir*1.2f,0.1f,-2.f,dir*-0.2f,-0.2f,-0.1f);

    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);
    gluQuadricTexture(quadric,GLU_FALSE);

    glPopMatrix();
}

void Gun::DrawCube(float posX,float posY,float posZ, float lX, float lY, float lZ)
{
    // position positives, l négatives
    glBegin(GL_QUADS);

    glNormal3f(0.0,0.0,1.0);
    glTexCoord2f(0,0);glVertex3f(posX,posY,posZ);
    glTexCoord2f(0,10);glVertex3f(posX+lX,posY,posZ);
    glTexCoord2f(10,10);glVertex3f(posX+lX,posY+lY,posZ);
    glTexCoord2f(10,0);glVertex3f(posX,posY+lY,posZ);

    glNormal3f(1.0,0.0,0.0);
    glTexCoord2f(0,0);glVertex3f(posX,posY,posZ);
    glTexCoord2f(0,10);glVertex3f(posX,posY,posZ+lZ);
    glTexCoord2f(10,10);glVertex3f(posX,posY+lY,posZ+lZ);
    glTexCoord2f(10,0);glVertex3f(posX,posY+lY,posZ);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2f(0,0);glVertex3f(posX,posY,posZ+lZ);
    glTexCoord2f(0,10);glVertex3f(posX+lX,posY,posZ+lZ);
    glTexCoord2f(10,10);glVertex3f(posX+lX,posY+lY,posZ+lZ);
    glTexCoord2f(10,0);glVertex3f(posX,posY+lY,posZ+lZ);

    glNormal3f(-1.0,0.0,0.0);
    glTexCoord2f(0,0);glVertex3f(posX+lX,posY,posZ);
    glTexCoord2f(0,10);glVertex3f(posX+lX,posY,posZ+lZ);
    glTexCoord2f(1,10);glVertex3f(posX+lX,posY+lY,posZ+lZ);
    glTexCoord2f(10,0);glVertex3f(posX+lX,posY+lY,posZ);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2f(0,0);glVertex3f(posX,posY,posZ);
    glTexCoord2f(0,10);glVertex3f(posX+lX,posY,posZ);
    glTexCoord2f(10,10);glVertex3f(posX+lX,posY,posZ+lZ);
    glTexCoord2f(10,0);glVertex3f(posX,posY,posZ+lZ);

    glNormal3f(0.0,-1.0,0.0);
    glTexCoord2f(0,0);glVertex3f(posX,posY+lY,posZ);
    glTexCoord2f(0,10);glVertex3f(posX+lX,posY+lY,posZ);
    glTexCoord2f(10,10);glVertex3f(posX+lX,posY+lY,posZ+lZ);
    glTexCoord2f(10,0);glVertex3f(posX,posY+lY,posZ+lZ);

    glEnd();
}

void Gun::angGunIncr(int sens)
{

    if(sens == 1 && angGun_<80)
    {
        angGun_+=1;
    }
    else if(angGun_>-45){
        angGun_+=-1;
    }
}

void Gun::elevationGunIncr(int sens)
{

    if(sens == 1 && elevation<20)
    {
        elevation+=1;
    }
    else if(elevation>5){
        elevation+=-1;
    }
}
