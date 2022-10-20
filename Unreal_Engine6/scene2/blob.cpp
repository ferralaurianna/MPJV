#include "blob.h"

using namespace std;

Blob::Blob(float posX,float posY,float posZ,float radius, int nbParticlesRow, int nbRows,int offset)
{

    position_=new Vector3D(posX,posY,posZ);
    radius_=radius;

    nucleus_= new Particles(0,0,0,1,(float)radius_/3,0,0);
    nbParticlesRow_=nbParticlesRow;
    nbRows_=nbRows;

    modelingBlob(offset);

}

void Blob::modelingBlob(int offset){
    vector<Particles[2]>* springs=new vector<Particles[2]>();
    Particles spring[2];

    vector<Particles*>* exteriorRow=new vector<Particles*>();
    Particles* exteriorParticle;
    int intervalRows=2*radius_/nbRows_;
    int intervalParticles=360/nbParticlesRow_;
    int offsetParticles=offset/nbParticlesRow_;


    // Creation of the particles on exterior rows
    for(int j=0;j<nbRows_;j++){
        for(int i=0;i<nbParticlesRow_;i++){

            float x=radius_*qSin(qDegreesToRadians(intervalParticles+offsetParticles));
            float y=radius_*qCos(qDegreesToRadians(intervalParticles+offsetParticles));
            float z=intervalRows*j-radius_;

            exteriorParticle=new Particles(x,y,z,(float)radius_/3,0,0);
            exteriorRow->push_back(exteriorParticle);

            // Creation of basic springs between particles of the row
            if(i>0){
                spring[0]=*exteriorRow->at(i-1);
                spring[1]=*exteriorRow->at(i);
                springs->push_back(spring);
                if(i==nbParticlesRow_-1){
                    spring[0]=*exteriorRow->at(exteriorRow->size());
                    spring[1]=*exteriorRow->at(0);
                    springs->push_back(spring);
                }
            }
        }
    }
    exteriorRow_=exteriorRow;
    for(Particles* part : *exteriorRow)
    {
        delete part;
    }
    delete exteriorRow;


    vector<Particles*>* interiorRow=new vector<Particles*>();
    Particles* interiorParticle;
    int intervalRowsInterior=2*radius_*0.7/nbRows_;

    // Creation of the particles on interior rows
    for(int j=0;j<nbRows_;j++){
        for(int i=0;i<nbParticlesRow_;i++){

            float x=radius_*0.7*qSin(qDegreesToRadians(intervalParticles+offsetParticles));
            float y=radius_*0.7*qCos(qDegreesToRadians(intervalParticles+offsetParticles));
            float z=intervalRowsInterior*j-radius_;

            interiorParticle=new Particles(x,y,z,(float)radius_/3,0,0);
            interiorRow->push_back(interiorParticle);

            // Creation of basic springs between particules of the row
            if(i>0){
                spring[0]=*interiorRow->at(i-1);
                spring[1]=*interiorRow->at(i);
                springs->push_back(spring);
            }

            // Creation of a spring between the new particle and the nucleus
            spring[0]=*interiorRow->at(i);
            spring[1]=*nucleus_;
            springs->push_back(spring);

            // Creation of a spring between the interior and exterior particle
            spring[0]=*exteriorRow->at(i);
            spring[1]=*interiorRow->at(i);
            springs->push_back(spring);

            // Creation of a diagonal spring between the interior and exterior particle
            spring[0]=*exteriorRow->at(i-1);
            spring[1]=*interiorRow->at(i);
            springs->push_back(spring);

            if(i==nbParticlesRow_-1){
                spring[0]=*interiorRow->at(interiorRow->size());
                spring[1]=*interiorRow->at(0);
                springs->push_back(spring);

                spring[0]=*exteriorRow->at(exteriorRow->size());
                spring[1]=*interiorRow->at(0);
                springs->push_back(spring);
            }
        }
    }
    interiorRow_=interiorRow;
    for(Particles* part : *interiorRow)
    {
        delete part;
    }
    delete interiorRow;

    // Creation of basic springs between the particles in the other direction
    for(int i=0;i<nbParticlesRow_;i++){
        for(int j=1;j<nbRows_;j++){

            if(j<nbRows_-1){
                spring[0]=*exteriorRow->at(i+j*nbParticlesRow_);
                spring[1]=*exteriorRow->at(i+(j+1)*nbParticlesRow_);
                springs->push_back(spring);

                spring[0]=*interiorRow->at(i+j*nbParticlesRow_);
                spring[1]=*interiorRow->at(i+(j+1)*nbParticlesRow_);
                springs->push_back(spring);

                spring[0]=*exteriorRow->at(i+j*nbParticlesRow_);
                spring[1]=*interiorRow->at(i+(j+1)*nbParticlesRow_);
                springs->push_back(spring);
            }
            else{
                spring[0]=*exteriorRow->at(i+j*nbParticlesRow_);
                spring[1]=*exteriorRow->at(i);
                springs->push_back(spring);

                spring[0]=*interiorRow->at(i+j*nbParticlesRow_);
                spring[1]=*interiorRow->at(i);
                springs->push_back(spring);

            }
        }
    }
    springs_=springs;
    delete springs;
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
    for (std::vector<Particles[2]>::iterator it = springs_->begin() ; it != springs_->end(); ++it){
        springDisplay((*it)[0],(*it)[1]);
    }

    //Getting back the world matrix before the translation from the stack
    glPopMatrix();
}

void Blob::springDisplay(Particles part1, Particles part2){

    Vector3D* springVector=new Vector3D(part2.getPosition()->getX()-part1.getPosition()->getX(),
                                        part2.getPosition()->getY()-part1.getPosition()->getY(),
                                        part2.getPosition()->getZ()-part1.getPosition()->getZ());

    float springNorm=springVector->norm();

    //Pushing the current world matrix in the stack
    glPushMatrix();

    glRotatef(0,0,1,0);
    glRotatef(0,0,0,1);

    //Drawing of the spring
    GLUquadric *quadric=gluNewQuadric();
    gluQuadricDrawStyle(quadric,GLU_FILL);

    gluCylinder(quadric,radius_*0.3/3,radius_*0.3/3,springNorm,50,50);

    //Getting back memory after the drawing
    gluDeleteQuadric(quadric);

    //Getting back the world matrix before the rotation from the stack
    glPopMatrix();
}
