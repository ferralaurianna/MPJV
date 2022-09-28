#include "gamegui.h"

#include <QRandomGenerator>
#include <iostream>
#include <QKeyEvent>
#include <QTimer>
#include <QtMath>
#include <QGenericMatrix>
#include <GL/glu.h>

using namespace std;

//const float PI=3.14159;


GameGUI::GameGUI(QWidget *parent): QOpenGLWidget(parent)
{
    // Initialize the instance of the objects to render at the first rendering (gun, ground...)
    gun=new Gun();
    scene=new Ground();
    score = 0;
    scoreBase=0;
    partType=0;
}

GameGUI::~GameGUI()
{
    // Manage the memory leak caused by the Particle vector
    for(Particles* part : particles)
    {
        delete part;
    }
}


// Initialize OpenGL parameters before the first rendering
void GameGUI::initializeGL()
{
    // Background color
    background=QColor(0,0,0,1);
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());

    // VERY IMPORTANT :: allow to draw with an automatic management of depth. DO NOT REMOVE.
    glEnable(GL_DEPTH_TEST);

    // Ambiant light
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_tab);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_tab);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_tab);

    glLightfv(GL_LIGHT0,GL_POSITION,light_tab_pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Loading of textures
    QImage texGrass = QImage(":/grass.jpg").convertToFormat(QImage::Format_RGBA8888);
    QImage texSky = QImage(":/sky.jpg").convertToFormat(QImage::Format_RGBA8888);
    QImage texWood = QImage(":/wood.jpg").convertToFormat(QImage::Format_RGBA8888);
    QImage texMetal = QImage(":/metal.jpg").convertToFormat(QImage::Format_RGBA8888);
    QImage texRocks = QImage(":/rocks.jpg").convertToFormat(QImage::Format_RGBA8888);


    // Storage of the scene's textures in a table
    texturesScene = new GLuint[3];

    glGenTextures(3,texturesScene);
    glBindTexture(GL_TEXTURE_2D,texturesScene[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4,texGrass.width(),texGrass.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texGrass.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);

    glBindTexture(GL_TEXTURE_2D,texturesScene[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4,texSky.width(),texSky.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texSky.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_MIRRORED_REPEAT);

    glBindTexture(GL_TEXTURE_2D,texturesScene[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4,texRocks.width(),texRocks.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texRocks.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);

    // Sending the table to the scene
    scene->sendTextures(texturesScene);

    // Storage of the gun's textures in a table
    texturesGun = new GLuint[2];

    glGenTextures(2,texturesGun);
    glBindTexture(GL_TEXTURE_2D,texturesGun[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4,texWood.width(),texWood.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texWood.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);

    glBindTexture(GL_TEXTURE_2D,texturesGun[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4,texMetal.width(),texMetal.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texMetal.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_MIRRORED_REPEAT);

    // Sending the table to the gun
    gun->sendTextures(texturesGun);

    resizeGL(width(),height());
}



void GameGUI::resizeGL(int width, int height)
{
    // Viewport definition
    glViewport(0, 0, width, height);
}


// General rendering management
void GameGUI::paintGL()
{
    // Clear background
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());
    // Clear depth
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    // Reinitializisation of the current projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.f, this->width()/this->height(), 5.f, 10000.f);

    // Reinitializisation of the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX_,cameraY_,cameraZ_, centralX_,centralY_,centralZ_, 0.,dirY,0.);

    // Colorize every single objects after that in white
    glColor3f(1, 1, 1);

    // Where to put the render methods to render object on the screen
    scene->Display();
    for(Particles* particle : particles)
    {
        particle->display();
    }
    gun->Display();

    updateScore();
    scene->slideSky();
}

// Manage the launching of the projectile
void GameGUI::launchPart()
{
    Particles* particle;
    // Create a particle with the right type according to the active type in the game
    switch(partType)
    {
        case 0:
        {
            particle=new Ball(gun->getposX(),gun->getElevation(),0.f,-180.f-gun->getAngle());
            break;
        }
        case 1:
        {
            particle=new Cannonball(gun->getposX(),gun->getElevation(),0.f,-180.f-gun->getAngle());
            break;
        }
        case 2:
        {
            particle=new FireBall(gun->getposX(),gun->getElevation(),0.f,-180.f-gun->getAngle());
            break;
        }
        case 3:
        {
            particle=new Laser(gun->getposX(),gun->getElevation(),0.f,-180.f-gun->getAngle());
            break;
        }
    }

    // Storage the new particle
    particles.push_back(particle);
}


// Manage the incrementation of the score according to the position of each particle on the ground
// and the score reached before the reset of the target and particles
void GameGUI::updateScore()
{
    score = 0;
    score+=scoreBase;
    int compteur = 0;
    for(Particles* particle : particles)
    {
       if(particle->isOnGround())
       {
           compteur++;
           Vector3D* pos = particle->getPosition();
           float cible = scene->getPosTarget();
           if((pos->getX()>cible-10) && (pos->getX()<cible+10))
           {
               score+=20;
           }
           else if((pos->getX()>cible-20) && (pos->getX()<cible+20))
           {
               score+=10;
           }
           else if((pos->getX()>cible-30) && (pos->getX()<cible+30))
           {
               score+=5;
           }
       }
    }
    // If the three shoots allowed for the same target's position are done, we reset the scene and storage
    // the new score reached for the next session of shoots
    if(compteur>2)
    {
        scoreBase=score;
        for(Particles* part : particles)
        {
            delete part;
        }
        particles.clear();
        scene->moveTarget();
    }
}

// Manage the switch of the projectile's type
void GameGUI::switchPartType()
{
    if(partType<3)
    {
        partType++;
    }
    else
    {
        partType=0;
    }
}

// Camera controls
void GameGUI::forwardCamera() {
    cameraX_ += cos(angleCamera_*PI/180);
    cameraZ_ -= sin(angleCamera_*PI/180);
    centralX_ += cos(angleCamera_*PI/180);
    centralZ_ -= sin(angleCamera_*PI/180);
}
void GameGUI::backwardCamera() {
    cameraX_ -= cos(angleCamera_*PI/180);
    cameraZ_ += sin(angleCamera_*PI/180);
    centralX_ -= cos(angleCamera_*PI/180);
    centralZ_ += sin(angleCamera_*PI/180);
}
void GameGUI::turnRightCamera() {
    angleCamera_ += 5;
    if (angleCamera_ > 360) {
        angleCamera_ -= 360;
    }
    cameraX_ = centralX_ - distanceCamera_*cos((angleCamera_)*PI/180);
    cameraZ_ = centralZ_ + distanceCamera_*sin((angleCamera_)*PI/180);
}
void GameGUI::turnLeftCamera() {
    angleCamera_ -= 5;
    if (angleCamera_ < 0) {
        angleCamera_ += 360;
    }
    cameraX_ = centralX_ - distanceCamera_*cos((angleCamera_)*PI/180);
    cameraZ_ = centralZ_ + distanceCamera_*sin((angleCamera_)*PI/180);
}
void GameGUI::zoomIn() {
    cameraX_ -= cos(angleCamera_*PI/180);
    cameraZ_ += sin(angleCamera_*PI/180);
    distanceCamera_+=1;
}
void GameGUI::zoomOut() {
    cameraX_ += cos(angleCamera_*PI/180);
    cameraZ_ -= sin(angleCamera_*PI/180);
    distanceCamera_-=1;
}
void GameGUI::goUp() {
    cameraY_+=1;
    centralY_+=1;
}
void GameGUI::goDown() {
    cameraY_-=1;
    centralY_-=1;
}
