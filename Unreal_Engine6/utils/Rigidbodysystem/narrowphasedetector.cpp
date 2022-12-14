#include "narrowphasedetector.h"
#include <tuple>

NarrowPhaseDetector::NarrowPhaseDetector(collisionRegistreryRigidody* detectedCols, std::vector<std::tuple<Actors*, Actors*>>* toTest)
{
    detectedCols_ = detectedCols;
    toTest_ = toTest;
}

void NarrowPhaseDetector::DetectCollision(std::vector<std::tuple<Actors*, Actors*>>* toTest)
{
    toTest_ = toTest;
    for(std::vector<std::tuple<Actors*, Actors*>>::iterator pCol = toTest->begin(); pCol != toTest->end(); ++pCol)
    {
        for(Primitives primAct1 : *std::get<0>(*pCol)->getPrimitives())
        {
            for(Primitives primAct2 : *std::get<1>(*pCol)->getPrimitives())
            {
                switch (primAct1.type) {
                case Primitives::SPHERE:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:
                        sphereSphere(std::get<0>(*pCol),primAct1,std::get<1>(*pCol),primAct2);

                        break;
                    case Primitives::BOX:
                        boxSphere(std::get<1>(*pCol),primAct2,std::get<0>(*pCol),primAct1);

                        break;
                    case Primitives::PLANE:
                        spherePlane(std::get<0>(*pCol),primAct1,std::get<1>(*pCol),primAct2);

                        break;
                    default:
                        break;
                    }

                    break;
                case Primitives::BOX:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:
                        boxSphere(std::get<0>(*pCol),primAct1,std::get<1>(*pCol),primAct2);

                        break;
                    case Primitives::BOX:

                        break;
                    case Primitives::PLANE:
                        boxPlane(std::get<0>(*pCol),primAct1,std::get<1>(*pCol),primAct2);

                        break;
                    default:
                        break;
                    }

                    break;
                case Primitives::PLANE:
                    switch (primAct2.type) {
                    case Primitives::SPHERE:
                        spherePlane(std::get<1>(*pCol),primAct2,std::get<0>(*pCol),primAct1);

                        break;
                    case Primitives::BOX:
                        boxPlane(std::get<1>(*pCol),primAct2,std::get<0>(*pCol),primAct1);

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

    Vector3D pos = *(act1->getRigidbody()->getPosition())+(distance.normalize())*S1.radiusOroffset_;

    if(distance.norm()<(S1.radiusOroffset_+S2.radiusOroffset_))
    {
        Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,distance.normalize(),S1.radiusOroffset_+S2.radiusOroffset_-distance.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
        detectedCols_->add(data);
    }
}

void NarrowPhaseDetector::spherePlane(Actors *act1, Primitives S1, Actors *act2, Primitives P2)
{
    Vector3D pos1 = *(act1->getRigidbody()->getPosition())+Vector3D(S1.localPosition_(0,0),S1.localPosition_(0,1),S1.localPosition_(0,2));

    float distance = pos1.scalarProduct(P2.normalOrhalfsize)-P2.radiusOroffset_-S1.radiusOroffset_;

    Vector3D pos = P2.normalOrhalfsize.normalize()*(distance+S1.radiusOroffset_);

    if(distance<0){
        Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,P2.normalOrhalfsize,distance,1,1,act1->getRigidbody(),act2->getRigidbody());
        detectedCols_->add(data);
    }

}

void NarrowPhaseDetector::boxPlane(Actors *act1, Primitives B1, Actors *act2, Primitives P2)
{
    Vector3D pos1 = *(act1->getRigidbody()->getPosition())+Vector3D(B1.localPosition_(0,0),B1.localPosition_(0,1),B1.localPosition_(0,2));
    Vector3D halfSize = B1.normalOrhalfsize;
    Vector3D posEdge;
    for(int i=0;i<8;i++){
        switch(i){
        case 0:{
            posEdge = pos1 + Vector3D(halfSize.getX(),-halfSize.getY(),halfSize.getZ());
            break;
        }
        case 1:{
            posEdge = pos1 + Vector3D(halfSize.getX(),-halfSize.getY(),-halfSize.getZ());
            break;
        }
        case 2:{
            posEdge = pos1 + Vector3D(-halfSize.getX(),-halfSize.getY(),-halfSize.getZ());
            break;
        }
        case 3:{
            posEdge = pos1 + Vector3D(-halfSize.getX(),-halfSize.getY(),halfSize.getZ());
            break;
        }
        case 4:{
            posEdge = pos1 + Vector3D(halfSize.getX(),halfSize.getY(),halfSize.getZ());
            break;
        }
        case 5:{
            posEdge = pos1 + Vector3D(halfSize.getX(),halfSize.getY(),-halfSize.getZ());
            break;
        }
        case 6:{
            posEdge = pos1 + Vector3D(-halfSize.getX(),halfSize.getY(),-halfSize.getZ());
            break;
        }
        case 7:{
            posEdge = pos1 + Vector3D(-halfSize.getX(),halfSize.getY(),halfSize.getZ());
            break;
        }
        }

        float distance = posEdge.scalarProduct(P2.normalOrhalfsize)-P2.radiusOroffset_;
        if(distance<0){
            Collisiondata data = Collisiondata(act1->getId(),act2->getId(),posEdge,P2.normalOrhalfsize,distance,1,1,act1->getRigidbody(),act2->getRigidbody());
            detectedCols_->add(data);
        }
    }
}

void NarrowPhaseDetector::boxSphere(Actors *act1, Primitives B1, Actors *act2, Primitives S2)
{
    Vector3D centerLocal = act1->getRigidbody()->getTransformMatrix()*(*act2->getRigidbody()->getPosition());
    Vector3D halfSize=B1.normalOrhalfsize;

    Vector3D closePoint=Vector3D(0,0,0);
    closePoint.setX(clamp(centerLocal,halfSize,0));
    closePoint.setY(clamp(centerLocal,halfSize,1));
    closePoint.setZ(clamp(centerLocal,halfSize,2));

     TYPE_COLLISION type=whichTypeCollision(closePoint,halfSize);
     switch(type){
     case TYPE_COLLISION::FACE_FACE_X:{
         Vector3D pos = *(act1->getRigidbody()->getPosition())+(closePoint.normalize())*S2.radiusOroffset_;
         Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,closePoint.normalize(),halfSize.getX()+S2.radiusOroffset_-closePoint.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
         detectedCols_->add(data);
     }
     case TYPE_COLLISION::FACE_FACE_Y:{
         Vector3D pos = *(act1->getRigidbody()->getPosition())+(closePoint.normalize())*S2.radiusOroffset_;
         Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,closePoint.normalize(),halfSize.getY()+S2.radiusOroffset_-closePoint.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
         detectedCols_->add(data);
     }
     case TYPE_COLLISION::FACE_FACE_Z:{
         Vector3D pos = *(act1->getRigidbody()->getPosition())+(closePoint.normalize())*S2.radiusOroffset_;
         Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,closePoint.normalize(),halfSize.getZ()+S2.radiusOroffset_-closePoint.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
         detectedCols_->add(data);
     }
     case TYPE_COLLISION::EDGE_FACE_XY:{
         Vector3D pos = Vector3D(halfSize.getX(),halfSize.getY(),closePoint.getZ());
         Vector3D posWorld = act1->getRigidbody()->getTransformMatrix().Inverse()*(*act1->getRigidbody()->getPosition());
         Vector3D posLocalSphere = act2->getRigidbody()->getTransformMatrix()*posWorld;
         Vector3D penetration = S2.normalOrhalfsize-posLocalSphere;
         Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,penetration.normalize(),penetration.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
         detectedCols_->add(data);
     }
     case TYPE_COLLISION::EDGE_FACE_ZY:{
         Vector3D pos = Vector3D(closePoint.getX(),halfSize.getY(),halfSize.getZ());
         Vector3D posWorld = act1->getRigidbody()->getTransformMatrix().Inverse()*(*act1->getRigidbody()->getPosition());
         Vector3D posLocalSphere = act2->getRigidbody()->getTransformMatrix()*posWorld;
         Vector3D penetration = S2.normalOrhalfsize-posLocalSphere;
         Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,penetration.normalize(),penetration.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
         detectedCols_->add(data);
     }
     case TYPE_COLLISION::EDGE_FACE_XZ:{
         Vector3D pos = Vector3D(halfSize.getX(),closePoint.getY(),halfSize.getZ());
         Vector3D posWorld = act1->getRigidbody()->getTransformMatrix().Inverse()*(*act1->getRigidbody()->getPosition());
         Vector3D posLocalSphere = act2->getRigidbody()->getTransformMatrix()*posWorld;
         Vector3D penetration = S2.normalOrhalfsize-posLocalSphere;
         Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,penetration.normalize(),penetration.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
         detectedCols_->add(data);
     }
     case TYPE_COLLISION::VERTEX_FACE:{
         Vector3D pos = Vector3D(halfSize.getX(),halfSize.getY(),halfSize.getZ());
         Vector3D posWorld = act1->getRigidbody()->getTransformMatrix().Inverse()*(*act1->getRigidbody()->getPosition());
         Vector3D posLocalSphere = act2->getRigidbody()->getTransformMatrix()*posWorld;
         Vector3D penetration = S2.normalOrhalfsize-posLocalSphere;
         Collisiondata data = Collisiondata(act1->getId(),act2->getId(),pos,penetration.normalize(),penetration.norm(),1,1,act1->getRigidbody(),act2->getRigidbody());
         detectedCols_->add(data);
     }
     }


}

float NarrowPhaseDetector::clamp(Vector3D centerLocal,Vector3D halfSize,int dimension){
    float distance=0;
    switch (dimension){
    case 0 :{
        distance = centerLocal.getX();
        if(distance>halfSize.getX()){
            distance=halfSize.getX();
        }
        if(distance<-halfSize.getX()){
            distance=-halfSize.getX();
        }
        break;
    }
    case 1 :{
        distance = centerLocal.getY();
        if(distance>halfSize.getY()){
            distance=halfSize.getY();
        }
        if(distance<-halfSize.getY()){
            distance=-halfSize.getY();
        }
        break;
    }
    case 2 :{
        distance = centerLocal.getZ();
        if(distance>halfSize.getZ()){
            distance=halfSize.getZ();
        }
        if(distance<-halfSize.getZ()){
            distance=-halfSize.getZ();
        }
        break;
    }
    }
    return distance;
}

NarrowPhaseDetector::TYPE_COLLISION NarrowPhaseDetector::whichTypeCollision(Vector3D closePoint,Vector3D halfSize){
    TYPE_COLLISION type=TYPE_COLLISION::FACE_FACE_X;

    int count=0;
    Vector3D countVec=Vector3D(0,0,0);

    if((abs(closePoint.getX()))==halfSize.getX()){
        count++;
        countVec.setX(1);
    }
    if((abs(closePoint.getY()))==halfSize.getY()){
        count++;
        countVec.setY(1);
    }
    if((abs(closePoint.getZ()))==halfSize.getZ()){
        count++;
        countVec.setZ(1);
    }

    switch(count){
    case 1:{
        if(countVec.getX()==1){
            type=TYPE_COLLISION::FACE_FACE_X;
        }
        if(countVec.getY()==1){
            type=TYPE_COLLISION::FACE_FACE_Y;
        }
        if(countVec.getZ()==1){
            type=TYPE_COLLISION::FACE_FACE_Z;
        }
        break;
    }
    case 2:{
        if(countVec.getX()==1&&countVec.getY()==1){
            type=TYPE_COLLISION::EDGE_FACE_XY;
        }
        if(countVec.getY()==1&&countVec.getZ()==1){
            type=TYPE_COLLISION::EDGE_FACE_ZY;
        }
        if(countVec.getX()==1&&countVec.getZ()==1){
            type=TYPE_COLLISION::EDGE_FACE_XZ;
        }
        break;
    }
    case 3:{
        type=TYPE_COLLISION::VERTEX_FACE;
        break;
    }
    }

    return type;
}
