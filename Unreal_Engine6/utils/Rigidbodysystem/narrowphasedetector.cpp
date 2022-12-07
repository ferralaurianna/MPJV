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

                        break;
                    case Primitives::BOX:

                        break;
                    case Primitives::PLANE:

                        break;
                    default:
                        break;
                    }

                    break;
                case Primitives::BOX:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:

                        break;
                    case Primitives::BOX:

                        break;
                    case Primitives::PLANE:

                        break;
                    default:
                        break;
                    }

                    break;
                case Primitives::PLANE:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:

                        break;
                    case Primitives::BOX:

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
