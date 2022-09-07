#include "gamegui.h"

#include <QRandomGenerator>
#include <iostream>
#include <QKeyEvent>
#include <QTimer>
#include <QtMath>
#include <QGenericMatrix>
#include <GL/glu.h>

using namespace std;

const float PI=3.14159;


GameGUI::GameGUI(QWidget *parent): QOpenGLWidget(parent)
{


}

GameGUI::~GameGUI(){

}


// Fonction d'initialisation
void GameGUI::initializeGL()
{
    // Reglage de la couleur de fond
    // ...
    fond=QColor(0,0,0,1);
    glClearColor(fond.redF(),fond.greenF(),fond.blueF(),fond.alphaF());

    glEnable(GL_DEPTH_TEST);

    //Initialise la lumière directionnelle
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_tab);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_tab);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_tab);

    glLightfv(GL_LIGHT0,GL_POSITION,light_tab_pos);
    glEnable(GL_LIGHT0);
}


// Fonction de redimensionnement
void GameGUI::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);
}


// Fonction d'affichage
void GameGUI::paintGL()
{
    glClearColor(fond.redF(),fond.greenF(),fond.blueF(),fond.alphaF());
    // Reinitialisation du tampon de couleur
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    // Reinitialisation de la matrice courante
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.f, this->width()/this->height(), 5.f, 800.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX_,cameraY_,cameraZ_, pointCentralX_,pointCentralY_,pointCentralZ_, 0.,dirY,0.);
    glPushMatrix();

    glColor3f(1, 1, 1);

    //Affichage des primitives
    glEnable(GL_LIGHTING);

    //Où doit être le vaisseau une fois finalisé

    glDisable(GL_LIGHTING);
    glPopMatrix();

}
