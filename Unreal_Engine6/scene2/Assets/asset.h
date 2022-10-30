#ifndef ASSET_H
#define ASSET_H
#include <vector>
#include "utils\Vector3D.h"

struct Polygone {
    Vector3D Sommet1;
    Vector3D Sommet2;
    Vector3D Sommet3;
    Vector3D Sommet4;
    Vector3D Norme;

    Polygone(Vector3D s1, Vector3D s2, Vector3D s3, Vector3D s4, Vector3D norme) :
        Sommet1(s1), Sommet2(s2), Sommet3(s3), Sommet4(s4), Norme(norme) {}
    };

class Asset
{
public:
    Asset();
    vector<Polygone> polygones;
};

#endif // ASSET_H
