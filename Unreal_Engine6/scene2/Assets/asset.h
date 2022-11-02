#ifndef ASSET_H
#define ASSET_H
#include <vector>
#include "utils\Vector3D.h"
#include "utils/polygon.h"


class Asset
{
public:
    Asset();

    vector<Polygone>* getPolygones(){return &polygones;};

protected:
    vector<Polygone> polygones;
};

#endif // ASSET_H
