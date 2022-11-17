#ifndef ASSET_H
#define ASSET_H
#include <vector>
#include "utils/polygon.h"


class Asset
{
public:
    Asset();

    std::vector<Polygone>* getPolygones(){return &polygones;};

protected:
    std::vector<Polygone> polygones;
};

#endif // ASSET_H
