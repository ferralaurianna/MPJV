#include "testVector.h"
#include "Vector3D.h"
#include <math.h>
#include <stdio.h>

void TestVector::constructor(){
    for(int i = 0; i < nbTest; i++){
        float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float z = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D vect = Vector3D(x, y, z);

        QVERIFY(vect.getX() == x);
        QVERIFY(vect.getY() == y);
        QVERIFY(vect.getZ() == z);
    }

    Vector3D vect = Vector3D();
    QVERIFY(vect.getX() == 0);
    QVERIFY(vect.getY() == 0);
    QVERIFY(vect.getZ() == 0);
}

void TestVector::operationByScalar(){
    Vector3D vect(1,2,5);

    for(int i = 0; i < nbTest; i++){
        float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D resultMult(r2, 2*r2, 5*r2);
        QVERIFY(resultMult == (vect*r2));
        Vector3D resultDiv(1/r2, 2/r2, 5/r2);
        Vector3D tmp = vect/r2;
        QVERIFY(resultDiv == (vect/r2));
    }
}

void TestVector::norm(){
    for(int i = 0; i < nbTest; i++){
        float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float z = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D vect(x, y, z);
        float realSquareNorm = x*x + y*y + z*z;
        float realNorm = sqrt(realSquareNorm); 
        QVERIFY(vect.norm() == realNorm);
        QVERIFY(vect.squareNorm() == realSquareNorm);
    }
}

void TestVector::normalization(){
    for(int i = 0; i < nbTest; i++){
        float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float z = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D vect(x, y, z);
        float realNorm = sqrt(x*x + y*y + z*z);
        Vector3D result(x/realNorm, y/realNorm, z/realNorm);
        QVERIFY(vect.normalize() == result);
    }
}

void TestVector::scalarProduct(){
    for(int i = 0; i < nbTest; i++){
        float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float z = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D vect(x,y,z);
        float otherX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float otherY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float otherZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D other(otherX,otherY,otherZ);
        QVERIFY(vect.scalarProduct(other) == (x*otherX + y*otherY + z*otherZ));
    }
}

void TestVector::operationBetweenVector(){ // Operation a faire: unaire.
    for(int i = 0; i < nbTest; i++){
        float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float z = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D vect(x,y,z);
        float otherX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float otherY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        float otherZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Vector3D other(otherX,otherY,otherZ);
        Vector3D resultAdd(x + otherX, y + otherY, z + otherZ);
        Vector3D resultSub(x - otherX, y - otherY, z - otherZ);
        Vector3D resultUnary(-x, -y, -z);
        Vector3D resultMult(x * otherX, y * otherY, z * otherZ);
        Vector3D resultVect(y * otherZ - z * otherY, z * otherX - x * otherZ, x * otherY - y * otherX);
        QVERIFY(vect+other == resultAdd);
        QVERIFY(vect-other == resultSub);
        QVERIFY(vect*other == resultMult);
        QVERIFY((vect^other) == resultVect);
        QVERIFY(-vect == resultUnary);
    }
}
