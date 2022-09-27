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
 * @brief The Ship class by Clément BOURLET
 * Ship gère le vaisseau dans la scène 3D, donc sa position et son dessin lorsque cela est nécessaire.
 */
class Gun
{
private:
    /**
     * @brief posX_, posY_ et posZ_
     * Enregistre la position du cannon dans la scène 3D.
     */
    float posX_;
    float posY_;
    float posZ_;
    /**
     * @brief angX_, angXRow_, angY_ et angYTemp_
     * Enregistre l'angle dans la scène 3D.
     */
    float angY_;
    float angGun_;
    float elevation;

    /**
     * @brief quadrique
     * Un pointeur vers l'instance de GLUQuadric nécessaire au dessin des quadriques du cannon.
     */
    GLUquadric* quadrique;
    /**
     * @brief Draw
     * Une fonction responsable du tracé de l'ensemble du cannon.
     */
    void Draw();
    /**
     * @brief DrawSupport
     * @param direction
     * Une fonction responsable du tracé d'un support latéral dans la direction donnée, avec la possibilité de changer la hauteur des taquets.
     */
    void DrawSupport(int direction);
    /**
     * @brief DrawGun
     * @param dir
     * DrawWing gère le tracé du cannon, avec la possiblité d'afficher un recul suite au tir en pourcentage et de changer l'angle du cannon.
     */
    void DrawGun(float recoil, float angleGun,float elevation);
    /**
     * @brief DrawGun
     * @param dir
     * DrawMechanics gère le tracé du cannon, avec la possiblité d'afficher un recul suite au tir en pourcentage et de changer l'angle du cannon.
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
