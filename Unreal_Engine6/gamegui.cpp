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
    //Initialize the instance of the objects to render (particules...)
    //example with one particule
    gun=new Gun();
    particule=new Particules(-5,0,0,0.1,1/100,30,0.7);
}

GameGUI::~GameGUI(){

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
    gluPerspective(80.f, this->width()/this->height(), 5.f, 75.f);

    // Reinitializisation of the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX_,cameraY_,cameraZ_, centralX_,centralY_,centralZ_, 0.,dirY,0.);

    // Colorize every single objects after that in white
    glColor3f(1, 1, 1);

    // Where to put the render methods to render object on the screen
    particule->display();
    gun->Display();
}

void GameGUI::launchPart()
{
    particule=new Particules(0.f,gun->getElevation(),0.f,1,1,1,1,45);
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
