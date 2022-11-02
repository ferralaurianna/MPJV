#ifndef PLATEFORME_H
#define PLATEFORME_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "asset.h"

class Plateforme : public Asset
{
public:
    Plateforme();

    // Constructeur Override
    Plateforme(float width, float length, float height, float posx, float posy, float posz);

    // Destructeur
    ~Plateforme();

    // Methode d'affichage
    void Display();

private:
    float widthx, lengthz, heighty;
    float posx, posy, posz;
};

#endif
