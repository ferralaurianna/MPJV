#include "forceregistreryrigidbody.h"

ForceRegistreryRigidbody::ForceRegistreryRigidbody()
{
    register_ = std::vector<Registration>();
}

void ForceRegistreryRigidbody::add(Rigidbody* particle, ForceGenerator* fg, int idSujet, int idOther)
{
    register_.push_back({particle,fg,idSujet,idOther});
}

void ForceRegistreryRigidbody::remove(int idSujet, int idOther)
{
    std::vector<Registration>::iterator it = register_.begin();
    while (it != register_.end()) {
      if (it->idSubject == idSujet && it->idOther == idOther) {
        delete it->forceGen;
        it = register_.erase(it);
      }
      else {
        ++it;
      }
    }
}

void ForceRegistreryRigidbody::removeAll(int idSujet)
{
    std::vector<Registration>::iterator it = register_.begin();
    while (it != register_.end()) {
      if (it->idSubject == idSujet) {
        delete it->forceGen;
        it = register_.erase(it);
      }
      else {
        ++it;
      }
    }
}

void ForceRegistreryRigidbody::clear()
{
    std::vector<Registration>::iterator it = register_.begin();
    while (it != register_.end()) {
        delete it->forceGen;
        it = register_.erase(it);
    }
}

void ForceRegistreryRigidbody::updateForces(float duration)
{
    for(Registration i: register_)
    {
        i.forceGen->updateForce(i.rigidbody,duration);
    }
}

ForceRegistreryRigidbody::~ForceRegistreryRigidbody()
{
    clear();
}
