#ifndef FORCEREGISTRERYRIGIDBODY_H
#define FORCEREGISTRERYRIGIDBODY_H

#include "generators/Rigibody/forcegenerator.h"
#include "generators/Rigibody/gravityforcegenerator.h"
#include "generators/Rigibody/springforcegenerator.h"
#include "generators/Rigibody/inputforcegenerator.h"
#include "utils/Rigidbodysystem/rigidbody.h"
#include <vector>

class ForceRegistreryRigidbody
{

    struct Registration
    {
        Rigidbody * rigidbody;
        ForceGenerator *forceGen;
        int idSubject;
        int idOther;
    };

public:
    ForceRegistreryRigidbody();
    ~ForceRegistreryRigidbody();

    //idOther is -1 for gravity and -2 for floatability
    void add(Rigidbody* rigidbody, ForceGenerator* fg, int idSujet, int idOther);

    void remove(int idSujet, int idOther);

    void removeAll(int idSujet);

    void clear();

    void updateForces(float duration);

private:
    std::vector<Registration> register_;
};

#endif // FORCEREGISTRERYRIGIDBODY_H
