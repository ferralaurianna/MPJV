#ifndef NARROWPHASEDETECTOR_H
#define NARROWPHASEDETECTOR_H


#include "utils/Rigidbodysystem/actors.h"
#include "utils/Rigidbodysystem/collisionregistreryrigidody.h"
class NarrowPhaseDetector
{
public:
    NarrowPhaseDetector(collisionRegistreryRigidody* detectedCols, std::vector<int[2]>* toTest);

    void addActor(Actors* act){actors_.push_back(act);};

    void removeActor(int id);

private:
    collisionRegistreryRigidody* detectedCols_;
    std::vector<int[2]>* toTest_;
    std::vector<Actors*> actors_;

    Actors* getActor(int id);
};

#endif // NARROWPHASEDETECTOR_H
