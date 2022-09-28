#include "testMatrix.h"
#include "utils\matrix.h"
#include <stdio.h>

//All the test are made with a 3x3 matrix.
void TestMatrix::operatorGetTest(){
    for(int i = 0; i < nbTest; i++){
        float *tab = new float[9]();
        for(int j = 0; j < 9; j++){
            tab[j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        }
        Matrix m(3, tab);
        for(int j = 0; j < 9; j++){
            QVERIFY(m(j / 3, j % 3) == tab[j]);
        }
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                QVERIFY(m[j][k] == tab[3*j+k]);
            }
        }
    }
}

void TestMatrix::operatorScalarTest(){
    for(int i = 0; i < nbTest; i++){
        float *tab = new float[9]();
        for(int j = 0; j < 9; j++){
            tab[j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        }
        Matrix m(3, tab);
        float scalar = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        Matrix resultProd = m*scalar;
        Matrix resultDiv = m/scalar;
        for(int j = 0; j < 9; j++){
            QVERIFY(resultProd(j / 3, j % 3) == (tab[j]*scalar));
            QVERIFY(resultDiv(j / 3, j % 3) == (tab[j]/scalar));
        }
    }
}

void TestMatrix::operatorMatrixTest(){
    for(int i = 0; i < nbTest; i++){
        float *tabOne = new float[9]();
        float *tabTwo = new float[9]();
        for(int j = 0; j < 9; j++){
            tabOne[j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
            tabTwo[j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
        }
        Matrix mOne(3, tabOne);
        Matrix mTwo(3, tabTwo);
        Matrix resultAdd = mOne + mTwo;
        Matrix resultSub = mOne - mTwo;

        for(int j = 0; j < 9; j++){
            QVERIFY(resultAdd(j / 3, j % 3) == (tabOne[j] + tabTwo[j]));
            QVERIFY(resultSub(j / 3, j % 3) == (tabOne[j] - tabTwo[j]));
        }        
    }
}
