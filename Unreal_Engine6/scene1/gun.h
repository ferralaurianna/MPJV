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
 * @brief The gun class
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
     * @brief Draw
     * A function that provide the OpenGL instructions necessary to draw the gun.
     */
    void Draw();
    /**
     * @brief DrawSupport
     * @param direction
     * A function that provide the OpenGL instructions necessary to draw the lateral support, with a variable to set to 0 or 1 to flip it along the Y axis.
     */
    void DrawSupport(int direction);
    /**
     * @brief DrawGun
     * @param recoil, angleGun, elevation
     * D function that provide the OpenGL instructions necessary to draw the gun itself, capable of handling changes of angle, elevation and recoil.
     */
    void DrawGun(float recoil, float angleGun,float elevation);
    /**
     * @brief DrawMechanics
     * @param elevation, angleGun, direction
     * DrawMechanics handle the the drawing of the mechanics connecting the gun to its support, moving along with change of elevation and angle. The direction variable is used to mirror it along the Y axis.
     */
    void DrawMechanics(float elevation, float angleGun, float direction);
    /**
     * @brief DrawGun
     * @param dir
     * DrawWing gère le tracé du cannon, avec la possiblité d'afficher un recul suite au tir en pourcentage et de changer l'angle du cannon.
     */
    void DrawCube(float posX,float posY,float posZ, float lX, float lY, float lZ);
    /**
     * @brief textures
     * Un pointeur vers la matrice des textures, utilisé pour lié les textures du cannon.
     */
    GLuint* textures;

public:
    // Constructeur avec parametres
    Gun();

    /**
     * @brief sendTextures
     * @param text
     * sendTextures permet de passer le pointeur vers la matrice des texture du GLwidget au vaisseau.
     */
    void sendTextures(GLuint* text);

    /**
     * @brief angGunIncr
     * @param sens
     * angGunIncr permet de faire varier l'angle du cannon dans les limites existantes dans un sens ou dans l'autre selon le paramètre.
     */
    void angGunIncr(int sens);

    /**
     * @brief angGunIncr
     * @param sens
     * elevationGunIncr permet de faire varier la hauteur du cannon dans les limites existantes dans un sens ou dans l'autre selon le paramètre.
     */
    void elevationGunIncr(int sens);

    // Destructeur
    ~Gun();

    /**
     * @brief Display
     * Display permet d'afficher le vaisseau.
     */
    void Display();

    float getElevation(){return elevation;}

    float getAngle(){return angGun_;}

    float getposX(){return posX_;}

};

#endif // SHIP_H
