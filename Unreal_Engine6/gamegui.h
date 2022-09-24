#ifndef GAMEGUI_H
#define GAMEGUI_H
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QObject>
#include <QWidget>
#include <particules.h>
#include <gun.h>
#include <vector>
#include <Ground.h>

class GameGUI:public QOpenGLWidget
{
public:
    GameGUI(QWidget *parent=nullptr);
    ~GameGUI();

    vector<Particules*> particules;
    Gun* gun;
    Ground* scene;


    QColor background;
    float centralX_=-20., centralY_=0., centralZ_=0.;
    float angleCamera_ = 90.;
    float distanceCamera_ = -200.;
    float cameraX_ = -20., cameraY_ = 25., cameraZ_ = distanceCamera_;
    float dirY=1;


    GLfloat light_tab[4]={1.0,1.0,1.0,1.0};
    GLfloat light_tab_pos[4]= {0.0,0.0,1.0,0.0};

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


protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    GLuint* texturesScene;
    GLuint* texturesGun;

};

#endif // GAMEGUI_H
