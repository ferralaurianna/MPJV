#include "collisionregistreryrigidody.h"

collisionRegistreryRigidody::collisionRegistreryRigidody()
{
    register_ = std::vector<Collisiondata>();
}

void collisionRegistreryRigidody::add(Collisiondata collision)
{
    register_.push_back(collision);
    std::cout << "COLLISION" << std::endl;
}

void collisionRegistreryRigidody::remove(int idSujet, int idOther)
{
    std::vector<Collisiondata>::iterator it = register_.begin();
    while (it != register_.end()) {
      if (it->idbody1 == idSujet && it->idbody2 == idOther) {
        it = register_.erase(it);
      }
      else {
        ++it;
      }
    }
}

void collisionRegistreryRigidody::removeAll(int idSujet)
{
    std::vector<Collisiondata>::iterator it = register_.begin();
    while (it != register_.end()) {
      if (it->idbody1 == idSujet || it->idbody2 == idSujet) {
        it = register_.erase(it);
      }
      else {
        ++it;
      }
    }
}

void collisionRegistreryRigidody::clear()
{
    std::vector<Collisiondata>::iterator it = register_.begin();
    while (it != register_.end()) {
        it = register_.erase(it);
    }
}

void collisionRegistreryRigidody::handleCollisions(float duration)
{
    for(Collisiondata i: register_)
    {

    }
}

collisionRegistreryRigidody::~collisionRegistreryRigidody()
{
    clear();
}

bool collisionRegistreryRigidody::hasCollisions()
{
    return !(register_.empty());
}

void collisionRegistreryRigidody::printCollisions()
{
    std::vector<Collisiondata>::iterator it = register_.begin();
    while (it != register_.end()) {
      std::cout << it.base();
    }
}
