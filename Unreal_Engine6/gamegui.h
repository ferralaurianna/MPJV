#ifndef GAMEGUI_H
#define GAMEGUI_H
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QObject>
#include <QWidget>

class GameGUI:public QOpenGLWidget
{
public:
    GameGUI(QWidget *parent=nullptr);
    ~GameGUI();


    QColor fond;
    float pointCentralX_=0., pointCentralY_=0., pointCentralZ_=0.;
    float angleCamera_ = 90.;
    float distanceCamera_ = -8.;
    float cameraX_ = 0., cameraY_ = 0., cameraZ_ = distanceCamera_;
    float dirY=1;


    GLfloat light_tab[4]={1.0,1.0,1.0,1.0};
    GLfloat light_tab_pos[4]= {0.0,0.0,1.0,0.0};

private:
    void avancerCamera();
    void reculerCamera();
    void tournerCameraDroite();
    void tournerCameraGauche();

protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

};

#endif // GAMEGUI_H
