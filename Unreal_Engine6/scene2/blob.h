#ifndef BLOB_H
#define BLOB_H

#include <utils/ParticlesSystem/particles.h>
#include <utils/Vector3D.h>
#include <vector>
#include <QtMath>

class Blob : public QObject
{
    Q_OBJECT

public:
    struct Link{
        Particles* part1;
        Particles* part2;
        float l0;
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
    std::vector<Particles*>* getExteriorRow(){return exteriorRow_;};
    std::vector<Particles*>* getInteriorRow(){return interiorRow_;};
    Particles* getNucleus(){return nucleus_;};
    std::vector<Link>* getSprings(){return springs_;};
    std::vector<Link>* getCables(){return cables_;};
    float getRadius(){return radius_;};

    bool shrinkBlob();

private:
    int nbParticlesRow_;
    int nbRows_;
    int offset_;

    std::vector<Particles*>* exteriorRow_ = new std::vector<Particles*>();
    std::vector<Particles*>* interiorRow_ = new std::vector<Particles*>();
    Particles* nucleus_;

    std::vector<Link>* springs_ = new std::vector<Link>();

    std::vector<Link>* cables_ = new std::vector<Link>();

    Vector3D* position_;
    float radius_;

    void springDisplay(Particles* part1, Particles* part2);

};

#endif // BLOB_H
