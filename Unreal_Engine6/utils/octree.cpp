#include "octree.h"
#include <algorithm>

void Octree::insert(BoundingVolume* element)
{
    if(isLeaf){
        if(std::find(elements.begin(), elements.end(), element)){ // L'element est deja present
            return;
        }
        if(elements.size() >= MAX_NUMBER_ELEMENT) // On regarde maintenant si on peut véritablement le mettre
        {
            isLeaf = false;
            for(BoundingVolume* elt : elements)
            {
                this->insert(elt);
            }
            elements.assign(MAX_NUMBER_ELEMENT, nullptr);
            this->insert(element);
        }
        else
        {
            elements.push_back(element);
        }
    }
    else // La partie fun commence, on regarde dans quel endroit le boundingVolume apparait et on l'insert dedans en récurisf.
    {

        int midx = (topLeftFront->x + bottomRightBack->x) / 2;
        int midy = (topLeftFront->y + bottomRightBack->y) / 2;
        int midz = (topLeftFront->z + bottomRightBack->z) / 2;
        if(element->intersectWithBox(topLeftFront->x, midy, topLeftFront->z, midx, bottomRightBack->y, midz))
        {
            children[0]->insert(element);
        }
        if(element->intersectWithBox(topLeftFront->x, midy, midz, midx, bottomRightBack->y, bottomRightBack->z))
        {
            children[1]->insert(element);
        }
        if(element->intersectWithBox(midx, midy, midz, bottomRightBack->x, bottomRightBack->y, bottomRightBack->z))
        {
            children[2]->insert(element);
        }
        if(element->intersectWithBox(midx, midy, topLeftFront->z, bottomRightBack->x, bottomRightBack->y, midz))
        {
            children[3]->insert(element);
        }
        if(element->intersectWithBox(topLeftFront->x, topLeftFront->y, topLeftFront->z, midx, midy, midz))
        {
            children[4]->insert(element);
        }
        if(element->intersectWithBox(topLeftFront->x, topLeftFront->y, midz, midx, midy, bottomRightBack->z))
        {
            children[5]->insert(element);
        }
        if(element->intersectWithBox(midx, topLeftFront->y, midz, bottomRightBack->x, midy, bottomRightBack->z))
        {
            children[6]->insert(element);
        }
        if(element->intersectWithBox(midx, topLeftFront->y, midz, bottomRightBack->x, midy, bottomRightBack->z))
        {
            children[7]->insert(element);
        }

    }
}

void Octree::remove(BoundingVolume* element) // TODO: Pas de merge encore effectuer !
{
    if(isLeaf)
    {
        for (int i = 0; i < elements.size(); i++)
        {
            if(element == elements.at(i))
            {
                elements.erase(elements.begin() + i);
                return;
            }
        }
    }
    else
    {
        for(int i = 0; i < children.size(); i++)
        {
            children[i]->remove(element);
        }
        // Faire le merge ici !
    }
}

std::vector<std::tuple<BoundingVolume*, BoundingVolume*>> Octree::findPossibleCollision()
{
    std::vector<std::tuple<BoundingVolume*, BoundingVolume*>> result;
    if(isLeaf)
    {
        for (int i = 0; i < elements.size() - 1; i++)
        {
            for (int j = i+1; j < elements.size(); ++j)
            {
                result.push_back(std::tuple<BoundingVolume*, BoundingVolume*>(elements[i], elements[j]));
            }
        }
    }
    else
    {
        std::vector<std::tuple<BoundingVolume*, BoundingVolume*>> tmp;
        for(int i = 0; i < children.size(); i++)
        {
            tmp = children[i]->findPossibleCollision();
            for(auto elt : tmp)
            {
                if(!std::find(result.begin(), result.end(), elt))
                {
                    result.push_back(elt);
                }
            }
        }
    }
    return result;
}
