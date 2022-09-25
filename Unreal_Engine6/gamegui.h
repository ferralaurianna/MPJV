#ifndef GAMEGUI_H
#define GAMEGUI_H
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QObject>
#include <QWidget>
#include <particles.h>
#include <gun.h>
#include <vector>
#include <Ground.h>
#include <iostream>
using namespace std;

class GameGUI:public QOpenGLWidget
{
public:
    GameGUI(QWidget *parent=nullptr);
    ~GameGUI();

    vector<Particles*> particles;
    Gun* gun;
    Ground* scene;

    //Camera controls to help for a better drawing of objects
    void forwardCamera();
    void backwardCamera();
    void turnRightCamera();
    void turnLeftCamera();
    void zoomIn();
    void zoomOut();
    void goUp();
    void goDown();

    void launchPart();

    void switchPartType();

    int getScore(){return score;}

    int getPartType(){return partType;}


protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();



private:
    int score;
    int scoreBase;
    int partType;

    GLuint* texturesScene;
    GLuint* texturesGun;

    void updateScore();

    QColor background;
    float centralX_=-20., centralY_=0., centralZ_=0.;
    float angleCamera_ = 90.;
    float distanceCamera_ = -200.;
    float cameraX_ = -20., cameraY_ = 25., cameraZ_ = distanceCamera_;
    float dirY=1;

    GLfloat light_tab[4]={1.0,1.0,1.0,1.0};
    GLfloat light_tab_pos[4]= {0.0,0.0,1.0,0.0};

};

#endif // GAMEGUI_H
