#include "boundingvolume.h"

BoundingVolume::BoundingVolume(Actors actor)
{

    // initialise les min et max des polygones
    float xmin = actor.getPolygones()->at(0).s0.getX();
    float xmax = actor.getPolygones()->at(0).s0.getX();
    float ymin = actor.getPolygones()->at(0).s0.getY();
    float ymax = actor.getPolygones()->at(0).s0.getY();
    float zmin = actor.getPolygones()->at(0).s0.getZ();
    float zmax = actor.getPolygones()->at(0).s0.getZ();

    // boucle pour determiner min et max sur chaque axe des polygones
    for ( auto it = actor.getPolygones()->begin(); it != actor.getPolygones()->end(); ++it)
    {
        xmin = std::min(xmin, it->s0.getX());
        xmin = std::min(xmin, it->s1.getX());
        xmin = std::min(xmin, it->s2.getX());
        xmin = std::min(xmin, it->s3.getX());

        xmax = std::max(xmax, it->s0.getX());
        xmax = std::max(xmax, it->s1.getX());
        xmax = std::max(xmax, it->s2.getX());
        xmax = std::max(xmax, it->s3.getX());

        ymin = std::min(ymin, it->s0.getY());
        ymin = std::min(ymin, it->s1.getY());
        ymin = std::min(ymin, it->s2.getY());
        ymin = std::min(ymin, it->s3.getY());

        ymax = std::max(ymax, it->s0.getY());
        ymax = std::max(ymax, it->s1.getY());
        ymax = std::max(ymax, it->s2.getY());
        ymax = std::max(ymax, it->s3.getY());

        zmin = std::min(zmin, it->s0.getZ());
        zmin = std::min(zmin, it->s1.getZ());
        zmin = std::min(zmin, it->s2.getZ());
        zmin = std::min(zmin, it->s3.getZ());

        zmax = std::max(zmax, it->s0.getZ());
        zmax = std::max(zmax, it->s1.getZ());
        zmax = std::max(zmax, it->s2.getZ());
        zmax = std::max(zmax, it->s3.getZ());

    }

    // le centre est situé au milieu des points les plus éloignés des polygones
    center = Point((xmin+xmax)/2,(ymin+ymax)/2,(zmin+zmax)/2);

    // Initialise la distance max entre 1 point des polygones et le centre du volume
    float distmax = sqrtf(pow(actor.getPolygones()->at(0).s0.getX() - center.x,2)
                         + pow(actor.getPolygones()->at(0).s0.getY() - center.y,2)
                         + pow(actor.getPolygones()->at(0).s0.getZ() - center.z,2) );

    // boucle pour determiner la distance la plus grande
    for ( auto it = actor.getPolygones()->begin(); it != actor.getPolygones()->end(); ++it) {

        distmax = std::max(distmax,sqrtf(pow(it->s0.getX() - center.x,2)
                                        + pow(it->s0.getY() - center.y,2)
                                        + pow(it->s0.getZ() - center.z,2) ) );

        distmax = std::max(distmax,sqrtf(pow(it->s1.getX() - center.x,2)
                                        + pow(it->s1.getY() - center.y,2)
                                        + pow(it->s1.getZ() - center.z,2) ) );

        distmax = std::max(distmax,sqrtf(pow(it->s2.getX() - center.x,2)
                                        + pow(it->s2.getY() - center.y,2)
                                        + pow(it->s2.getZ() - center.z,2) ) );

        distmax = std::max(distmax,sqrtf(pow(it->s3.getX() - center.x,2)
                                        + pow(it->s3.getY() - center.y,2)
                                        + pow(it->s3.getZ() - center.z,2) ) );
    }

    // le rayon du volume est égale à cette distance
    radius = distmax;
}

bool BoundingVolume::intersectWithBox(int xTopLeftFront, int yTopLeftFront, int zTopLeftFront, int xBottomRightBack, int yBottomRightBack, int zBottomRightBack)
{
    float xBoxCenter = (xTopLeftFront + xBottomRightBack)/2;
    float yBoxCenter = (yTopLeftFront + yBottomRightBack)/2;
    float zBoxCenter = (zTopLeftFront + zBottomRightBack)/2;
    float width = abs(xTopLeftFront - xBottomRightBack);
    float height = abs(yTopLeftFront - yBottomRightBack);
    float length = abs(zTopLeftFront - zBottomRightBack);

    float sphereXDistance = abs(center.x - xBoxCenter);
    float sphereYDistance = abs(center.y - yBoxCenter);
    float sphereZDistance = abs(center.z - zBoxCenter);

    if (sphereXDistance >= (width + radius)) { return false; }
    if (sphereYDistance >= (height + radius)) { return false; }
    if (sphereZDistance >= (length + radius)) { return false; }

    if (sphereXDistance < width) { return true; }
    if (sphereYDistance < height) { return true; }
    if (sphereZDistance < length) { return true; }

    float cornerDistance_sq = ((sphereXDistance - width) * (sphereXDistance - width)) +
                         ((sphereYDistance - height) * (sphereYDistance - height) +
                         ((sphereYDistance - length) * (sphereYDistance - length)));

    return (cornerDistance_sq < (radius * radius));
}


















