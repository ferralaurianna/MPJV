#include "octree.h"
#include <algorithm>

void Octree::add(Actors *actor)
{
    BoundingVolume *bv = new BoundingVolume(actor);
    this->insert(bv);
}


void Octree::insert(BoundingVolume* element)
{
    if(isLeaf){
        if(std::find(elements.begin(), elements.end(), element) != elements.end()){ // L'element est deja present
            return;
        }
        if(elements.size() >= MAX_NUMBER_ELEMENT) // On regarde maintenant si on peut véritablement le mettre
        {
            this->makeLeaf();
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


void Octree::update(int idActor)
{
    BoundingVolume* bv = this->remove(idActor);
    bv->Update();
    this->insert(bv);
}


BoundingVolume* Octree::remove(int idActor)
{
    if(isLeaf)
    {
        for (int i = 0; i < (int) elements.size(); i++)
        {
            if(idActor == elements.at(i)->getActor()->getId())
            {
                BoundingVolume *bv = elements.at(i);
                elements.erase(elements.begin() + i);
                return bv;
            }
        }
        return nullptr;
    }
    else
    {
        BoundingVolume *toReturn = nullptr;
        for(int i = 0; i < (int) children.size(); i++)
        {
            BoundingVolume *bv = children[i]->remove(idActor);
            if(bv != nullptr){
                toReturn = bv;
            }
        }
        std::vector<BoundingVolume*> tmp = this->getUniqueElements();
        if(tmp.size() < MAX_NUMBER_ELEMENT)
        {
            elements = tmp;
            children.assign(8, nullptr);
        }

        return toReturn;
    }
}



void Octree::remove(BoundingVolume* element)
{
    if(isLeaf)
    {
        for (int i = 0; i < (int) elements.size(); i++)
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
        for(int i = 0; i < (int) children.size(); i++)
        {
            children[i]->remove(element);
        }
        std::vector<BoundingVolume*> tmp = this->getUniqueElements();
        if(tmp.size() < MAX_NUMBER_ELEMENT)
        {
            elements = tmp;
            children.assign(8, nullptr);
        }
    }
}


std::vector<BoundingVolume*> Octree::getUniqueElements()
{
    std::vector<BoundingVolume*> result;
    if(isLeaf)
    {
        return elements;
    }
    std::vector<BoundingVolume*> tmp;
    for(int i = 0; i < (int) children.size(); i++)
    {
        tmp = children[i]->getUniqueElements();
        for(auto elt : tmp)
        {
            if(std::find(result.begin(), result.end(), elt) == result.end())
            {
                result.push_back(elt);
            }
        }
    }
    return result;
}

std::vector<Actors*[2]> Octree::findPossibleCollision()
{
    std::vector<Actors*[2]> result;
    if(isLeaf)
    {
        if(elements.size() < 2){
            return result;
        }
        for (int i = 0; i < (int) elements.size() - 1; i++)
        {
            for (int j = i+1; j < (int) elements.size(); ++j)
            {
                result.push_back({elements[i]->getActor(), elements[j]->getActor()});
            }
        }
    }
    else
    {
        std::vector<Actors*[2]> tmp;
        for(int i = 0; i < (int) children.size(); i++)
        {
            tmp = children[i]->findPossibleCollision();
            for(int i = 0; i < (int) tmp.size(); i++)
            {
                if(std::find(result.begin(), result.end(), tmp.at(i)) == result.end())
                {
                    result.push_back(tmp.at(i));
                }
            }
        }
    }
    return result;
}
