#include "narrowphasedetector.h"

NarrowPhaseDetector::NarrowPhaseDetector(collisionRegistreryRigidody* detectedCols, std::vector<int[2]>* toTest)
{
    detectedCols_ = detectedCols;
    toTest_ = toTest;
    actors_ = std::vector<Actors*>();
}

void NarrowPhaseDetector::removeActor(int id)
{
    std::vector<Actors*>::iterator it;
    while(it!=actors_.end())
    {
        if(**it == id)
        {
            actors_.erase(it);
        }
        else
        {
            it++;
        }
    }
}
