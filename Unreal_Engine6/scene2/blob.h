#ifndef BLOB_H
#define BLOB_H

#include <utils/particles.h>
#include <utils/Vector3D.h>
#include <vector>
#include <QtMath>

class Blob
{
public:
    Blob(float posX=0,float posY=0,float posZ=0,float radius=3, int nbParticlesRow=20, int nbRows=5, int offset=0);

    // Creation of the links and particles of the blob
    void modelingBlob(int offset);

    // Rendering method
    void display();
    void springDisplay(Particles part1, Particles part2);

    // Setters
    //void setExteriorRow(std::vector<Particles*>* exteriorRow){exteriorRow_=exteriorRow;};
    //void setInteriorRow(std::vector<Particles*>* interiorRow){interiorRow_=interiorRow;};
    //void setNucleus(Particles* nucleus){nucleus_=nucleus;};
    //void setSprings(std::vector<Particles[2]>* springs){springs_=springs;};
    // Getters
    std::vector<Particles*>* getExteriorRow(){return exteriorRow_;};
    std::vector<Particles*>* getInteriorRow(){return interiorRow_;};
    Particles* getNucleus(){return nucleus_;};
    std::vector<Particles[2]>* getSprings(){return springs_;};

private:
    int nbParticlesRow_;
    int nbRows_;

    std::vector<Particles*>* exteriorRow_;
    std::vector<Particles*>* interiorRow_;
    Particles* nucleus_;

    std::vector<Particles[2]>* springs_;

    Vector3D* position_;
    float radius_;
};

#endif // BLOB_H
