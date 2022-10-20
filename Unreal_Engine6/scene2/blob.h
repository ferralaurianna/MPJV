#ifndef BLOB_H
#define BLOB_H

#include <utils/particles.h>
#include <utils/Vector3D.h>
#include <vector>
#include <QtMath>

class Blob
{
public:
    struct Link{
        Particles* part1;
        Particles* part2;
    };
    Blob(float posX=0,float posY=0,float posZ=0,float radius=20, int nbParticlesRow=20, int nbRows=7, int offset=0);
    ~Blob();

    // Creation of the links and particles of the blob
    void modelingBlob(int offset);

    // Rendering method
    void display();

    // Setters
    //void setExteriorRow(std::vector<Particles*>* exteriorRow){exteriorRow_=exteriorRow;};
    //void setInteriorRow(std::vector<Particles*>* interiorRow){interiorRow_=interiorRow;};
    //void setNucleus(Particles* nucleus){nucleus_=nucleus;};
    //void setSprings(std::vector<Particles[2]>* springs){springs_=springs;};
    // Getters
    vector<Particles*>* getExteriorRow(){return exteriorRow_;};
    vector<Particles*>* getInteriorRow(){return interiorRow_;};
    Particles* getNucleus(){return nucleus_;};
    std::vector<Link>* getSprings(){return springs_;};

private:
    int nbParticlesRow_;
    int nbRows_;

    vector<Particles*>* exteriorRow_ = new vector<Particles*>();
    vector<Particles*>* interiorRow_ = new vector<Particles*>();
    Particles* nucleus_;

    std::vector<Link>* springs_;

    Vector3D* position_;
    float radius_;

    void springDisplay(Particles* part1, Particles* part2);
};

#endif // BLOB_H
