#ifndef PLATEFORME_H
#define PLATEFORME_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>


class Plateforme
{
public:
    Plateforme();

    // Constructeur Override
    Plateforme(float width, float length, float height, float posx, float posy, float posz);

    // Destructeur
    ~Plateforme();

    // Methode d'affichage
    void Display() const;

    // vector position
    std::vector<float> Pos;

private:
    float widthx, lengthz, heighty;
    float posx, posy, posz;
};

#endif
