#ifndef GAMEGUI_H
#define GAMEGUI_H
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QObject>
#include <QWidget>
#include "utils\particles.h"
#include "bulletsType\ball.h"
#include "bulletsType\cannonball.h"
#include "bulletsType\laser.h"
#include "bulletsType\fireball.h"
#include "gun.h"
#include <vector>
#include "ground.h"
#include <iostream>

using namespace std;

class GameGUI:public QOpenGLWidget
{
public:
    /**
     * @brief GameGUI
     * The constructor of the Ground class.
     */
    GameGUI(QWidget *parent=nullptr);
    /**
     * @brief ~GameGUI
     * The destructor of the Ground class.
     */
    ~GameGUI();

    /**
     * @brief particles
     * A list of pointers to the particles present in the scene.
     */
    vector<Particles*> particles;
    /**
     * @brief gun, scene
     * Pointers to the objects used to draw the gun and the background.
     */
    Gun* gun;
    Ground* scene;

    /**
     * @brief forwardCamera
     * A function used to move the camera and its center of view formward.
     */
    void forwardCamera();
    /**
     * @brief backwardCamera
     * A function used to move the camera  and its center of view  backward.
     */
    void backwardCamera();
    /**
     * @brief turnRightCamera
     * A function used to rotate the camera to the right around its center of view.
     */
    void turnRightCamera();
    /**
     * @brief turnLeftCamera
     * A function used to rotate the camera to the left around its center of view.
     */
    void turnLeftCamera();
    /**
     * @brief zoomIn
     * A function used to move the camera toward its center of view.
     */
    void zoomIn();
    /**
     * @brief zoomOut
     * A function used to move the camera away from its center of view.
     */
    void zoomOut();
    /**
     * @brief goUp
     * A function used to move the camera and its center of view up.
     */
    void goUp();
    /**
     * @brief goDown
     * A function used to move the camera and its center of view down.
     */
    void goDown();

    /**
     * @brief launchPart
     * A function used to spawn a new particle of the current type.
     */
    void launchPart();
    /**
     * @brief switchPartType
     * A function used to spawn cycle to the next particle type.
     */
    void switchPartType();

    int getScore(){return score;}

    int getPartType(){return partType;}


protected:
    /**
     * @brief initializeGL
     * A function used to initialize the OpenGL scene.
     */
    void initializeGL();

    /**
     * @brief resizeGL
     * A function used to resize the OpenGL scene.
     */
    void resizeGL(int width, int height);

    /**
     * @brief paintGL
     * The function called each frame to draw the 3D scene.
     */
    void paintGL();



private:
    /**
     * @brief score, scoreBase and partType
     * Integers used to store the current score, the cumulated score of previous 3-bullets cycles and the currently selected type of particle.
     */
    int score;
    int scoreBase;
    int partType;

    /**
     * @brief texturesScene, texturesGun
     * Pointers to the texure matrixes used to texture the background and the gun.
     */
    GLuint* texturesScene;
    GLuint* texturesGun;

    /**
     * @brief updateScore
     * A function called to calculate the current score.
     */
    void updateScore();

    /**
     * @brief background
     * The default background color.
     */
    QColor background;

    /**
     * @brief centralX_, centralY_, centralZ_
     * Floats used to store the position of the camera's center of view.
     */
    float centralX_=-20., centralY_=0., centralZ_=0.;
    /**
     * @brief angleCamera_, distanceCamera_
     * Floats used to store the relative angle and distance between the camera and the X axis and it's center of view.
     */
    float angleCamera_ = 90.;
    float distanceCamera_ = -200.;
    /**
     * @brief cameraX_, cameraY_, cameraZ_
     * Floats used to store the position of the camera.
     */
    float cameraX_ = -20., cameraY_ = 25., cameraZ_ = distanceCamera_;
    /**
     * @brief dirY
     * A float indicating if the view of the camera has been reversed.
     */
    float dirY=1;

    GLfloat light_tab[4]={1.0,1.0,1.0,1.0};
    GLfloat light_tab_pos[4]= {0.0,0.0,1.0,0.0};

};

#endif // GAMEGUI_H
