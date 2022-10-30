#include "blob.h"
#include <iostream>
using namespace std;

Blob::Blob(float posX,float posY,float posZ,float radius, int nbParticlesRow, int nbRows,int offset)
{

    position_=new Vector3D(posX,posY,posZ);
    radius_=radius;

    nucleus_= new Particles(0,0,0,(float)radius_/5,100,0,0);
    nbParticlesRow_=nbParticlesRow;
    nbRows_=nbRows;

    modelingBlob(offset);

}

void Blob::modelingBlob(int offset){
    springs_=new vector<Link>();
    cables_=new vector<Link>();
    Link spring;
    Link cable;

    Particles* exteriorParticle;
    float intervalRows=2*radius_/(float(nbRows_-1));
    int intervalParticles=360/nbParticlesRow_;
    int offsetParticles=offset/nbParticlesRow_;


    // Creation of the particles on exterior rows
    for(int j=0;j<nbRows_-2;j++){
        for(int i=0;i<nbParticlesRow_;i++){

            float factrad = qSin(qAcos(1-2*(float(j+1)/float(nbRows_-1))));
            float x=radius_*qSin(qDegreesToRadians(intervalParticles*i+offsetParticles))*factrad;
            float y=radius_*qCos(qDegreesToRadians(intervalParticles*i+offsetParticles))*factrad;
            float z=intervalRows*float(j+1)-radius_;

            exteriorParticle=new Particles(x,y,z,(float)radius_/20,1,0,0);
            exteriorRow_->push_back(exteriorParticle);

            // Creation of basic springs between particles of the row
            if(i>0){
                spring.part1=exteriorRow_->at((i+j*nbParticlesRow_)-1);
                spring.part2=exteriorParticle;
                spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
                springs_->push_back(spring);
                if(i==nbParticlesRow_-1){
                    spring.part1=exteriorParticle;
                    spring.part2=exteriorRow_->at(j*nbParticlesRow_);
                    spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
                    springs_->push_back(spring);
                }
            }
        }
    }

    Particles* interiorParticle;
    float intervalRowsInterior=2*radius_*0.7/(float(nbRows_-1));

    // Creation of the particles on interior rows
    for(int j=0;j<nbRows_-2;j++){
        for(int i=0;i<nbParticlesRow_;i++){

            float factrad = qSin(qAcos(1-2*(float(j+1)/float(nbRows_-1))));
            float x=radius_*0.7*qSin(qDegreesToRadians(intervalParticles*i+offsetParticles))*factrad;
            float y=radius_*0.7*qCos(qDegreesToRadians(intervalParticles*i+offsetParticles))*factrad;
            float z=intervalRowsInterior*float(j+1)-radius_*0.7;

            interiorParticle=new Particles(x,y,z,(float)radius_/20,1,0,0);
            interiorRow_->push_back(interiorParticle);

            // Creation of basic springs between particules of the row
            if(i>0){
                spring.part1=interiorRow_->at((i+j*nbParticlesRow_)-1);
                spring.part2=interiorParticle;
                spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
                springs_->push_back(spring);
                if(i==nbParticlesRow_-1){
                    spring.part1=interiorParticle;
                    spring.part2=interiorRow_->at(j*nbParticlesRow_);
                    spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
                    springs_->push_back(spring);
                }
            }

            // Creation of a spring between the new particle and the nucleus
            spring.part1=interiorParticle;
            spring.part2=nucleus_;
            spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
            springs_->push_back(spring);
            cable.part1=interiorParticle;
            cable.part2=nucleus_;
            cable.l0= 1.4*((*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm());
            cables_->push_back(cable);

            // Creation of a spring between the interior and exterior particle
            spring.part1=exteriorRow_->at(i+j*nbParticlesRow_);
            spring.part2=interiorParticle;
            spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
            springs_->push_back(spring);

            // Creation of a diagonal spring between the interior and exterior particle
            if(i>0)
            {
                spring.part1=exteriorRow_->at(i+j*nbParticlesRow_-1);
                spring.part2=interiorParticle;
                spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
                springs_->push_back(spring);
            }
            else
            {
                spring.part1=exteriorRow_->at(nbParticlesRow_-1+j*nbParticlesRow_);
                spring.part2=interiorParticle;
                spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
                springs_->push_back(spring);
            }
        }
    }

    // Creation of basic springs between the particles in the other direction
    for(int i=0;i<nbParticlesRow_;i++){
        for(int j=0;j<nbRows_-3;j++){
            spring.part1=exteriorRow_->at(i+j*nbParticlesRow_);
            spring.part2=exteriorRow_->at(i+(j+1)*nbParticlesRow_);
            spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
            springs_->push_back(spring);

            spring.part1=interiorRow_->at(i+j*nbParticlesRow_);
            spring.part2=interiorRow_->at(i+(j+1)*nbParticlesRow_);
            spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
            springs_->push_back(spring);

            spring.part1=exteriorRow_->at(i+j*nbParticlesRow_);
            spring.part2=interiorRow_->at(i+(j+1)*nbParticlesRow_);
            spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
            springs_->push_back(spring);
        }
    }

    //Creation and connection of the unique lower summits
    exteriorParticle=new Particles(0,0,-radius_,(float)radius_/20,1,0,0);
    exteriorRow_->push_back(exteriorParticle);
    interiorParticle=new Particles(0,0,-radius_*0.7,(float)radius_/20,1,0,0);
    interiorRow_->push_back(interiorParticle);

    spring.part1=exteriorParticle;
    spring.part2=interiorParticle;
//    spring.part2=nucleus_;
    spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
    springs_->push_back(spring);

    spring.part1=interiorParticle;
    spring.part2=nucleus_;
    spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
    springs_->push_back(spring);

    for(int i=0; i<nbParticlesRow_;i++)
    {
        spring.part1=interiorRow_->at(i);
        spring.part2=interiorParticle;
        spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
        springs_->push_back(spring);

        cable.part1=interiorRow_->at(i);
        cable.part2=interiorParticle;
        cable.l0= 1.3*((*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm());
        cables_->push_back(cable);
    }

    for(int i=0; i<nbParticlesRow_;i++)
    {
        spring.part1=exteriorRow_->at(i);
        spring.part2=exteriorParticle;
        spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
        springs_->push_back(spring);

        cable.part1=exteriorRow_->at(i);
        cable.part2=exteriorParticle;
        cable.l0= 1.3*((*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm());
        cables_->push_back(cable);
    }

    //Creation and connection of the unique upper summits
    exteriorParticle=new Particles(0,0,radius_,(float)radius_/20,1,0,0);
    exteriorRow_->push_back(exteriorParticle);
    interiorParticle=new Particles(0,0,radius_*0.7,(float)radius_/20,1,0,0);
    interiorRow_->push_back(interiorParticle);

    spring.part1=exteriorParticle;
    spring.part2=interiorParticle;
//    spring.part2=nucleus_;
    spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
    springs_->push_back(spring);

    spring.part1=interiorParticle;
    spring.part2=nucleus_;
    spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
    springs_->push_back(spring);

    for(int i=0; i<nbParticlesRow_;i++)
    {
        spring.part1=interiorRow_->at(i+nbParticlesRow_*(nbRows_-3));
        spring.part2=interiorParticle;
        spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
        springs_->push_back(spring);

        cable.part1=interiorRow_->at(i);
        cable.part2=interiorParticle;
        cable.l0= 1.3*((*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm());
        cables_->push_back(cable);
    }

    for(int i=0; i<nbParticlesRow_;i++)
    {
        spring.part1=exteriorRow_->at(i+nbParticlesRow_*(nbRows_-3));
        spring.part2=exteriorParticle;
        spring.l0= (*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm();
        springs_->push_back(spring);

        cable.part1=exteriorRow_->at(i);
        cable.part2=exteriorParticle;
        cable.l0= 1.3*((*(spring.part1->getPosition())-*(spring.part2->getPosition())).norm());
        cables_->push_back(cable);
    }

}

void Blob::display(){

    //Pushing the current world matrix in the stack
    glPushMatrix();

    //When position vector added, correct this line and uncomment
    glTranslatef(position_->getX(),position_->getY(),position_->getZ());

    //Rendering of the particles
    for(Particles* part : *interiorRow_){
        part->display();
    }

    for(Particles* part : *exteriorRow_){
        part->display();
    }

    //Rendering of the springs
    for(Link spring : *springs_)
    {
        springDisplay(spring.part1,spring.part2);
    }

    nucleus_->display();

    //Getting back the world matrix before the translation from the stack
    glPopMatrix();
}

void Blob::springDisplay(Particles* part1, Particles* part2){

    Vector3D springVector= *(part1->getPosition()) - *(part2->getPosition());

    float springNorm=springVector.norm();
    float flatNorm = -qSqrt(springVector.getZ()*springVector.getZ()+springVector.getX()*springVector.getX());

    //Pushing the current world matrix in the stack
    glPushMatrix();
    Vector3D* posP2 = part2->getPosition();
//    cout<<part2->getPosition()->getX()<<endl;
    glTranslatef(posP2->getX(),posP2->getY(),posP2->getZ());

    float angY = qAcos(springVector.getZ()/flatNorm)*(1-2*(springVector.getX()>0));
    float angX = (qAsin(springVector.getY()/springNorm)+3.1415);

    glRotatef(qRadiansToDegrees(angY),0,1,0);
    glRotatef(qRadiansToDegrees(angX),1,0,0);

    //Drawing of the spring
    GLUquadric *quadric=gluNewQuadric();
    gluQuadricDrawStyle(quadric,GLU_FILL);

    gluCylinder(quadric,radius_*0.3/20,radius_*0.3/20,springNorm,50,50);

    //Getting back memory after the drawing
    gluDeleteQuadric(quadric);

    //Getting back the world matrix before the rotation from the stack
    glPopMatrix();

}

Blob::~Blob()
{
    delete nucleus_;
    for(Particles* part: *exteriorRow_)
    {
        delete part;
    }
    for(Particles* part: *interiorRow_)
    {
        delete part;
    }
    delete interiorRow_;
    delete exteriorRow_;
    delete position_;
}
