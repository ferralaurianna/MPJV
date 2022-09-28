#ifndef GUN_H
#define GUN_H


#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <algorithm>
#include <math.h>

#define PI 3.14159265

/**
 * @brief The Gun class
 * Gun handle the position of the gun in the 3D scene and provide a function to draw it.
 */
class Gun
{
private:
    /**
     * @brief posX_, posY_ and posZ_
     * Register the position of the gun in the scene.
     */
    float posX_;
    float posY_;
    float posZ_;
    /**
     * @brief angY_, angGun and elevation
     * Register the parameters of the gun that change when aiming.
     */
    float angY_;
    float angGun_;
    float elevation;

    /**
     * @brief quadrique
     * A pointer to an instance of GLUquadric necessary to draw quadrics
     */
    GLUquadric* quadric;
    /**
     * @brief textures
     * A pointer to the texure matrix used to texture the gun.
     */
    GLuint* textures;

    /**
     * @brief Draw
     * A function that provide the OpenGL instructions necessary to draw the gun.
     */

    void Draw();
    /**
     * @brief DrawSupport
     * @param direction
     * A function that provide the OpenGL instructions necessary to draw the lateral support, with a variable direction to flip it along the Y axis.
     */
    void DrawSupport(bool direction);
    /**
     * @brief DrawGun
     * @param recoil, angleGun, elevation
     * A function that provide the OpenGL instructions necessary to draw the gun itself, capable of handling changes of angle, elevation and recoil.
     */
    void DrawGun(float recoil, float angleGun,float elevation);
    /**
     * @brief DrawMechanics
     * @param elevation, angleGun, direction
     * A function that provide the OpenGL instructions necessary to draw the mechanics connecting the gun to its support, moving along with change of elevation and angle.
     * The direction variable is used to mirror it along the Y axis.
     */
    void DrawMechanics(float elevation, float angleGun, bool direction);
    /**
     * @brief DrawGun
     * @param posX, posY, posZ, lX, lY, lZ
     * A function that provide the OpenGL instructions necessary to draw a cube. Takes positive sizes and mimimumposition along each axis for proper texture orientation.
     */
    void DrawCube(float posX,float posY,float posZ, float lX, float lY, float lZ);

public:
    /**
     * @brief Gun
     * The constructor of the Gun class
     */
    Gun();

    /**
     * @brief sendTextures
     * @param text
     * sendTextures is used to pass the pointer to a texture matrix to a gun object.
     */
    void sendTextures(GLuint* text);

    /**
     * @brief angGunIncr
     * @param dir
     * angGunIncr is used to change the gun's angle, the parameter allow to choose the direction of the change.
     */
    void angGunIncr(int dir);

    /**
     * @brief angGunIncr
     * @param dir
     * elevationGunIncr is used to change the gun's height, the parameter allow to choose the direction of the change.
     */
    void elevationGunIncr(int dir);

    /**
     * @brief ~Gun
     * The destructor of the Gun class.
     */
    ~Gun();

    /**
     * @brief Display
     * Display is called to draw the gun in the scene.
     */
    void Display();

    float getElevation(){return elevation;}

    float getAngle(){return angGun_;}

    float getposX(){return posX_;}

};

#endif // SHIP_H
