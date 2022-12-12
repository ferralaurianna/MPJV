#include "narrowphasedetector.h"

NarrowPhaseDetector::NarrowPhaseDetector(collisionRegistreryRigidody* detectedCols, std::vector<Actors*[2]>* toTest)
{
    detectedCols_ = detectedCols;
    toTest_ = toTest;
}

void NarrowPhaseDetector::DetectCollision()
{
    for(Actors** pCol : *toTest_)
    {
        for(Primitives primAct1 : *pCol[0]->getPrimitives())
        {
            for(Primitives primAct2 : *pCol[1]->getPrimitives())
            {
                switch (primAct1.type) {
                case Primitives::SPHERE:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:
                        sphereSphere(pCol[0],primAct1,pCol[1],primAct2);

                        break;
                    case Primitives::BOX:
                        boxSphere(pCol[1],primAct2,pCol[0],primAct1);

                        break;
                    case Primitives::PLANE:
                        spherePlane(pCol[0],primAct1,pCol[1],primAct2);

                        break;
                    default:
                        break;
                    }

                    break;
                case Primitives::BOX:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:
                        boxSphere(pCol[0],primAct1,pCol[1],primAct2);

                        break;
                    case Primitives::BOX:

                        break;
                    case Primitives::PLANE:
                        boxPlane(pCol[0],primAct1,pCol[1],primAct2);

                        break;
                    default:
                        break;
                    }

                    break;
                case Primitives::PLANE:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:
                        spherePlane(pCol[1],primAct2,pCol[0],primAct1);

                        break;
                    case Primitives::BOX:
                        boxPlane(pCol[1],primAct2,pCol[0],primAct1);

                        break;
                    case Primitives::PLANE:

                        break;
                    default:
                        break;
                    }

                    break;
                default:
                    break;
                }
            }
        }
    }
}

void NarrowPhaseDetector::sphereSphere(Actors* act1, Primitives S1, Actors* act2, Primitives S2)
{
    Vector3D pos1 = *(act1->getRigidbody()->getPosition())+Vector3D(S1.localPosition_(0,0),S1.localPosition_(0,1),S1.localPosition_(0,2));
    Vector3D pos2 = *(act2->getRigidbody()->getPosition())+Vector3D(S2.localPosition_(0,0),S2.localPosition_(0,1),S2.localPosition_(0,2));
    Vector3D distance = pos1-pos2;

    Vector3D pos = *(act1->getRigidbody()->getPosition())+(distance.normalize())*S1.getPropFloat();

    if(distance.norm()<(S1.getPropFloat()+S2.getPropFloat()))
    {
        Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,distance.normalize(),S1.getPropFloat()+S2.getPropFloat()-distance.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
        detectedCols_->add(data);
    }
}

void NarrowPhaseDetector::spherePlane(Actors *act1, Primitives S1, Actors *act2, Primitives P2)
{

}

void NarrowPhaseDetector::boxPlane(Actors *act1, Primitives B1, Actors *act2, Primitives P2)
{

}

void NarrowPhaseDetector::boxSphere(Actors *act1, Primitives B1, Actors *act2, Primitives S2)
{

}
