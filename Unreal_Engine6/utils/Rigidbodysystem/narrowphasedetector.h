#ifndef NARROWPHASEDETECTOR_H
#define NARROWPHASEDETECTOR_H


#include "utils/Rigidbodysystem/actors.h"
#include "utils/Rigidbodysystem/collisionregistreryrigidody.h"
class NarrowPhaseDetector
{
public:
    NarrowPhaseDetector(collisionRegistreryRigidody* detectedCols, std::vector<Actors*[2]>* toTest);

    void DetectCollision();

private:
    collisionRegistreryRigidody* detectedCols_;
    std::vector<Actors*[2]>* toTest_;
};

#endif // NARROWPHASEDETECTOR_H
