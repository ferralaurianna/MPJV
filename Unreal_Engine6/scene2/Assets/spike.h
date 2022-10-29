#ifndef SPIKE_H
#define SPIKE_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>


class Spike
{
public:
    Spike();

    //Constructeur Override
    Spike(float side, float posx, float posy, float posz);

    // Methode d'affichage
    void Display() const;

    // vector position
    std::vector<float> Pos;
private:
    float side;
    float posx, posy, posz;
};

#endif // SPIKE_H
