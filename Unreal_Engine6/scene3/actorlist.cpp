#include "actorlist.h"
#include <algorithm>

ActorList::ActorList()
{
}

void ActorList::addActor(Actors actor)
{
    int id = actor.getId();
    list.push_back(actor);
    for(Actors::Connection link : *actor.getLinks())
    {
        addLink(id,link.idOther,link.bodyAnchor_,link.otherBodyAnchor_);
    }
    for(Actors::Connection cable : *actor.getLinks())
    {
        addCable(id,cable.idOther,cable.bodyAnchor_,cable.otherBodyAnchor_);
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
    physic_->addSimpleForce(act->getRigidbody(),id,-1,-1);
}

void ActorList::addLink(int id, int idOther,Vector3D bodyAnchor, Vector3D otherBodyAnchor)
{
    Actors* act = getActor(id);
    act->addLink(idOther,bodyAnchor,otherBodyAnchor);
    physic_->addForcesBetween(id,idOther,1,act->getRigidbody(),bodyAnchor);
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
    return &(*it);
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
        act.getRigidbody()->integrate(duration);
    }
}
