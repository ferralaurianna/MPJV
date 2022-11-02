#ifndef GAMEGUI2_H
#define GAMEGUI2_H
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QObject>
#include <QWidget>
#include "scene2\blob.h"
#include "scene2\gametimer2.h"
#include <vector>
#include <QRandomGenerator>
#include <QTimer>
#include <QtMath>
#include <QGenericMatrix>
#include <GL/glu.h>

class GameGUI2:public QOpenGLWidget
{
public:
    /**
     * @brief GameGUI2
     * The constructor of the GameGUI2 class.
     */
    GameGUI2(QWidget *parent=nullptr);
    /**
     * @brief ~GameGUI2
     * The destructor of the GameGUI2 class.
     */
    ~GameGUI2();

    /**
     * @brief particles
     * A list of pointers to the particles present in the scene.
     */
    vector<Blob*> blobs_;

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

    int getScore(){return score;}


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

    GameTimer2 *gameTimer;

private:
    /**
     * @brief score, scoreBase and partType
     * Integers used to store the current score, the cumulated score of previous 3-bullets cycles and the currently selected type of particle.
     */
    int score;
    int scoreBase;

    /**
     * @brief texturesScene, texturesGun
     * Pointers to the texure matrixes used to texture the background and the gun.
     */
    GLuint* texturesScene;
    GLuint* texturesGun;


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

    /**
     * @brief light_tab, light_tab_pos
     * GLfloats that store the intensity and positions of the lights
     */
    GLfloat light_tab[4]={1.0,1.0,1.0,1.0};
    GLfloat light_tab_pos[4]= {0.0,0.0,1.0,0.0};

};

#endif // GAMEGUI2_H
