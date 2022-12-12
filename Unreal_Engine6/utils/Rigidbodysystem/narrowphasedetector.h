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

    void sphereSphere(Actors *act1, Primitives S1, Actors *act2, Primitives S2);
    void spherePlane(Actors *act1, Primitives S1, Actors *act2, Primitives P2);
    void boxPlane(Actors *act1, Primitives B1, Actors *act2, Primitives P2);
    void boxSphere(Actors *act1, Primitives B1, Actors *act2, Primitives S2);
};

#endif // NARROWPHASEDETECTOR_H
