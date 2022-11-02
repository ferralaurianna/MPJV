#include "collisiondetector.h"

CollisionDetector::CollisionDetector(CollisionRegistrery* registery, vector<vector<Polygone> *> *walls)
{
    registery_ = registery;
    walls_ = walls;
}

void CollisionDetector::detectCollision(Particles* part)
{
    Vector3D normed = part->getInitialVelocity()->normalize();
    Vector3D position = *(part->getPosition());
    float contactFront = 0;
    float contactBack = 0;
    float distance = 0;
    Vector3D normalSurf;
    for(vector<Polygone> *wall : *walls_)
    {
        for(Polygone p : *wall)
        {
            int result = 0;
            if(p.s3.getX()==-14 && p.s3.getY()==-7 && p.s3.getZ()==-1789)
            {
                result = rayTriangleIntersect(position,normed,p.s0,p.s1,p.s2);
            }
            else
            {
                result = rayRectangleIntersect(position,normed,p.s0,p.s1,p.s2,p.s3);
            }
            if(result == 1)
            {
                contactFront++;
            }
            else if(result == -1)
            {
                contactBack++;
                normalSurf=((p.s1-p.s0)^(p.s2-p.s0)).normalize();
//                cout<<normalSurf.getX()<<endl;
//                cout<<normalSurf.getY()<<endl;
//                cout<<normalSurf.getZ()<<endl;
//                cout<<endl;
                distance = (position-P).scalarProduct(normalSurf)/normalSurf.norm();
            }
        }
        if(contactBack == 1 && contactFront ==1)
        {
            ParticleContact contact = ParticleContact(part,-normalSurf,100,distance);
            registery_->add(contact);
        }
    }
}

int CollisionDetector::rayTriangleIntersect(
    Vector3D orig, Vector3D dir,
    Vector3D v0, Vector3D v1, Vector3D v2)
{
    // compute plane's normal
    Vector3D v0v1 = v1 - v0;
    Vector3D v0v2 = v2 - v0;
    // no need to normalize
    Vector3D N = v0v1^v0v2;  //N

    // Step 1: finding P

    // check if ray and plane are parallel.
    float NdotRayDirection = N.scalarProduct(dir);
    if (fabs(NdotRayDirection) < 0.001)  //almost 0
        return false;  //they are parallel so they don't intersect !

    float d = -N.scalarProduct(v0);

    float t = -(N.scalarProduct(orig) + d) / NdotRayDirection;

    // check if the triangle is in behind the ray
    if (t < 0) return false;  //the triangle is behind

    // compute the intersection point using equation 1
    Vector3D P = orig + dir * t;

    // Step 2: inside-outside test
    Vector3D C;  //vector perpendicular to triangle's plane

    // edge 0
    Vector3D edge0 = v1 - v0;
    Vector3D vp0 = P - v0;
    C = edge0^(vp0);
    if (N.scalarProduct(C) < 0) return false;

    // edge 1
    Vector3D edge1 = v2 - v1;
    Vector3D vp1 = P - v1;
    C = edge1^(vp1);
    if (N.scalarProduct(C) < 0)  return false;

    // edge 2
    Vector3D edge2 = v0 - v2;
    Vector3D vp2 = P - v2;
    C = edge2^(vp2);
    if (N.scalarProduct(C) < 0) return false;

    return true;  //this ray hits the triangle
}

int CollisionDetector::rayRectangleIntersect(
    Vector3D orig, Vector3D dir,
    Vector3D v0, Vector3D v1, Vector3D v2, Vector3D v3)
{
    float frontBack = 1;
    // compute plane's normal
    Vector3D v0v1 = v1 - v0;
    Vector3D v0v2 = v2 - v0;
    // no need to normalize
    Vector3D N = v0v1^v0v2;  //N

    // Step 1: finding P

    // check if ray and plane are parallel.
    float NdotRayDirection = N.scalarProduct(dir);
    if (fabs(NdotRayDirection) < 0.001)  //almost 0
        return 0;  //they are parallel so they don't intersect !

    float d = -N.scalarProduct(v0);

    float t = -(N.scalarProduct(orig) + d) / NdotRayDirection;

    // check if the rectangle is in behind the ray
    if (t < 0) frontBack = -1;

    // compute the intersection point using equation 1
    P = orig + dir * t;

    // Step 2: inside-outside test
    Vector3D C;  //vector perpendicular to rectangle's plane

    // edge 0
    Vector3D edge0 = v1 - v0;
    Vector3D vp0 = P - v0;
    C = edge0^(vp0);
    if (N.scalarProduct(C) < 0) return 0;

    // edge 1
    Vector3D edge1 = v2 - v1;
    Vector3D vp1 = P - v1;
    C = edge1^(vp1);
    if (N.scalarProduct(C) < 0)  return 0;

    // edge 2
    Vector3D edge2 = v3 - v2;
    Vector3D vp2 = P - v2;
    C = edge2^(vp2);
    if (N.scalarProduct(C) < 0) return 0;

    // edge 3
    Vector3D edge3 = v0 - v3;
    Vector3D vp3 = P - v3;
    C = edge3^(vp3);
    if (N.scalarProduct(C) < 0) return 0;

    return frontBack;  //this ray hits the rectangle
}
