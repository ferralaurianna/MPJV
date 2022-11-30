#include "actorlist.h"
#include <algorithm>

ActorList::ActorList()
{
    list.reserve(1000);
}

void ActorList::addActor(Actors actor)
{
    int id = actor.getId();
    list.push_back(actor);
    Actors* act = getActor(id);
    if(actor.getGrav())
    {
        physic_->addSimpleForce(act->getRigidbody(),id,-1);;
    }
    if(actor.getCol())
    {
        physic_->addToCollision(id,act);
    }
}

void ActorList::removeActor(int id)
{
    physic_->removeForces(id);
    std::vector<Actors>::iterator it;
    it = std::find(list.begin(), list.end(), id);
    if(it!=list.end())
    {
        list.erase(it);
    }
}

void ActorList::removeGravity(int id)
{
    Actors* act = getActor(id);
    act->setGrav(false);
    physic_->removeForce(id,-1);
}

void ActorList::addGravity(int id)
{
    Actors* act = getActor(id);
    act->setGrav(true);
    physic_->addSimpleForce(act->getRigidbody(),id,-1);
}

void ActorList::addLink(int id, int idOther,Vector3D bodyAnchor, Vector3D otherBodyAnchor)
{
    Actors* act = getActor(id);
    Actors* other = getActor(idOther);
    act->addLink(idOther,bodyAnchor,otherBodyAnchor);
    physic_->addForcesBetween(id,idOther,1,act->getRigidbody(),bodyAnchor,other->getRigidbody(),otherBodyAnchor);
}

void ActorList::removeLink(int id, int idOther)
{
    Actors* act = getActor(id);
    act->removeLink(id,idOther);
    physic_->removeForce(id,idOther);
}

void ActorList::addCable(int id, int idOther,Vector3D bodyAnchor, Vector3D otherBodyAnchor)
{
    Actors* act = getActor(id);
    act->addCable(idOther,bodyAnchor,otherBodyAnchor);
}

void ActorList::removeCable(int id, int idOther)
{
    Actors* act = getActor(id);
    act->removeCable(id,idOther);
}

Actors* ActorList::getActor(int id)
{
    std::vector<Actors>::iterator it;
    it = std::find(list.begin(), list.end(), id);
    if(it!=list.end())
    {
        return &(*it);
    }
    return nullptr;
}

void ActorList::clearForces()
{
    for(Actors act : list)
    {
        act.getRigidbody()->clearAccum();
    }
}

void ActorList::integrateAll(float duration)
{
    for(Actors act : list)
    {
        if(act.willMove())
        {
            physic_->addMoved(act.getId());
        }
        act.getRigidbody()->integrate(duration);
    }
}

void ActorList::removecollisions(int id)
{
    Actors* act = getActor(id);
    act->setCol(false);
    physic_->removeCollisions(id);
}

void ActorList::addCollisions(int id)
{
    Actors* act = getActor(id);
    act->setCol(true);
    physic_->addToCollision(id,act);
}
