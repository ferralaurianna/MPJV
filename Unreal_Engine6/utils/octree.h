#ifndef OCTREE_H
#define OCTREE_H

#define MAX_NUMBER_ELEMENT 6

#include "boundingvolume.h"

#include <vector>
#include <tuple>

/**
 * Pour information d'utilisation de la classe:
 * le child 0 est la box en bas a gauche devant.
 * le child 1 est la box en bas a gauche derrière.
 * le child 2 est la box en bas a droite derriere.
 * le child 3 est la box en bas a droite devant.
 * le child 4 est la box en haut a gauche devant.
 * le child 5 est la box en haut a gauche derrière.
 * le child 6 est la box en haut a droite derriere.
 * le child 7 est la box en haut a droite devan
 */

class Octree
{
private:
    std::vector<BoundingVolume*> elements;
    Point *topLeftFront, *bottomRightBack;
    std::vector<Octree*> children;
    bool isLeaf = true; // De base, tout les octrees creer sont des feuilles.

    void makeLeaf()
    {
        isLeaf = false;
        int midx = (topLeftFront->x + bottomRightBack->x) / 2;
        int midy = (topLeftFront->y + bottomRightBack->y) / 2;
        int midz = (topLeftFront->z + bottomRightBack->z) / 2;
        children[0] = new Octree(topLeftFront->x, midy, topLeftFront->z, midx, bottomRightBack->y, midz);
        children[1] = new Octree(topLeftFront->x, midy, midz, midx, bottomRightBack->y, bottomRightBack->z);
        children[2] = new Octree(midx, midy, midz, bottomRightBack->x, bottomRightBack->y, bottomRightBack->z);
        children[3] = new Octree(midx, midy, topLeftFront->z, bottomRightBack->x, bottomRightBack->y, midz);
        children[4] = new Octree(topLeftFront->x, topLeftFront->y, topLeftFront->z, midx, midy, midz);
        children[5] = new Octree(topLeftFront->x, topLeftFront->y, midz, midx, midy, bottomRightBack->z);
        children[6] = new Octree(midx, topLeftFront->y, midz, bottomRightBack->x, midy, bottomRightBack->z);
        children[7] = new Octree(midx, topLeftFront->y, topLeftFront->z, bottomRightBack->x, midy, midz);

        for(BoundingVolume* elt : elements)
        {
            this->insert(elt);
        }
        elements.clear();
    }

public:
    //Constructor
    Octree() = delete;
    // Constructor with six arguments
    Octree(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        // This use to construct Octree
        // with boundaries defined
        if (x2 < x1
            || y2 < y1
            || z2 < z1) {
            return;
        }

        topLeftFront = new Point(x1, y1, z1);
        bottomRightBack = new Point(x2, y2, z2);

        // Assigning null to the children
        children.assign(8, nullptr);
    }
    void add(Actors* actor);
    void insert(BoundingVolume* element);
    void update(int idActor);
    BoundingVolume* remove(int idActor);
    void remove(BoundingVolume* element);
    std::vector<Actors*[2]> findPossibleCollision();
    std::vector<BoundingVolume*> getUniqueElements();

};

#endif // OCTREE_H
