#ifndef ACTORSASSET_H
#define ACTORSASSET_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "utils/Vector3D.h"
#include "utils/Polygon.h"
#include "utils/Rigidbodysystem/actors.h"
#include <math.h>

class ActorsAsset
{
public:

    // Constructeur Override
    ActorsAsset(Actors* actor, float width, float length, float height);

    // Destructeur
    ~ActorsAsset();

    // Methode d'affichage
    void Display();

private:
    float widthx, lengthz, heighty;

    Actors* actor_;
};

#endif // ACTORSASSET_H

