#ifndef GAMEGUI4_H
#define GAMEGUI4_H
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QObject>
#include <QWidget>
#include <vector>
#include <QRandomGenerator>
#include <QTimer>
#include <QtMath>
#include <QGenericMatrix>
#include <GL/glu.h>
#include "scene3/actorlist.h"

class gamegui4: public QOpenGLWidget
{

public:
    /**
     * @brief GameGUI4
     * The constructor of the GameGUI4 class.
     */
    gamegui4(QWidget *parent=nullptr);
    /**
     * @brief ~GameGUI4
     * The destructor of the GameGUI4 class.
     */
    ~gamegui4();

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

    void setactorList(ActorList* actorlist_);

    void DrawPolygone(Polygone polygone, int id);

    std::vector<Polygone> CreateCubePolygone(float x,float y,float z,float lx,float ly,float lz);

    Polygone CreatePlane(float x,float y,float z,float lx,float ly,float lz, int xyz);

    void demo();

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
     * @brief background
     * The default background color.
     */
    QColor background;

    /**
     * @brief centralX_, centralY_, centralZ_
     * Floats used to store the position of the camera's center of view.
     */
    float centralX_=0., centralY_=0., centralZ_=0.;
    /**
     * @brief angleCamera_, distanceCamera_
     * Floats used to store the relative angle and distance between the camera and the X axis and it's center of view.
     */
    float angleCamera_ = 90.;
    float distanceCamera_ = -3.;
    /**
     * @brief cameraX_, cameraY_, cameraZ_
     * Floats used to store the position of the camera.
     */
    float cameraX_ = 0., cameraY_ = 3., cameraZ_ = distanceCamera_;
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
    GLfloat light_tab_pos[4]= {0,4.0,0.0,0.0}; // modif pour une lumière en (0,9,0) (1 pour qu'elle soit positionnelle

    ActorList* pactorList;

};

#endif // GAMEGUI4_H

