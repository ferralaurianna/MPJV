#ifndef NARROWPHASEDETECTOR_H
#define NARROWPHASEDETECTOR_H


#include "utils/Rigidbodysystem/actors.h"
#include "utils/Rigidbodysystem/collisionregistreryrigidody.h"
class NarrowPhaseDetector
{
public:
    NarrowPhaseDetector(collisionRegistreryRigidody* detectedCols, std::vector<Actors*[2]>* toTest);

    void DetectCollision(std::vector<Actors*[2]>* toTest);

private:
    collisionRegistreryRigidody* detectedCols_;
    std::vector<Actors*[2]>* toTest_;

    void sphereSphere(Actors *act1, Primitives S1, Actors *act2, Primitives S2);
    void spherePlane(Actors *act1, Primitives S1, Actors *act2, Primitives P2);
    void boxPlane(Actors *act1, Primitives B1, Actors *act2, Primitives P2);
    void boxSphere(Actors *act1, Primitives B1, Actors *act2, Primitives S2);
    float clamp(Vector3D centerLocal, Vector3D halfSize, int dimension);

    typedef enum  {
            VERTEX_FACE = 0,
            EDGE_FACE_XY = 1,
            EDGE_FACE_ZY = 2,
            EDGE_FACE_XZ = 3,
            FACE_FACE_X = 4,
            FACE_FACE_Y = 5,
            FACE_FACE_Z = 6,
        } TYPE_COLLISION;
    TYPE_COLLISION whichTypeCollision(Vector3D closePoint,Vector3D halfSize);
};

#endif // NARROWPHASEDETECTOR_H
