#ifndef COIN_H
#define COIN_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "asset.h"


class Coin : public Asset
{
public:
    Coin();
    //Constructeur override
    Coin(float radius, float height, float posx, float posy, float posz);
    // Destructeur
    ~Coin();

    // Methode d'affichage
    void Display();

private :
    GLUquadric* quad;
    float radius, height;
    float posx, posy, posz;
};

#endif // COIN_H
