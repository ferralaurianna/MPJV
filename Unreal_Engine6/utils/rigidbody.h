#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "utils/particles.h"


class Rigidbody : Particles
{
public:

    /**
     * @brief Rigidbody
     * posX, posY, posZ, radius, mass, velocity, orientation, angular velocity
     * The constructor of the Rigidbody class, with many physical variables as parameters.
     */
    Rigidbody(float posX=0,float posY=0,float posZ=0,float radius=1,float mass=1,float velocity=1,float orientation=45,float rotation=1);
    ~Rigidbody();

    // Rendering
    void display();

    // Getters / Setters
    Quaternion * getOrientation(){ return orientation_ ; };
    void setOrientation(Quaternion * orientation){ orientation_ = orientation; };
    Vector3D * getRotation(){ return rotation_ ; };
    void setRotation(Vector3D * rotation){ rotation_ = rotation; };

    /**
     * Integrates the rigidbody, by modifiying position, orientation & velocity
     * @param duration seconds
     */
    void integrate(float duration);

protected:

    // Orientation of the rigidbody
    // TODO change for new type (or QQuaternion)
    Quaternion * orientation_ = new Quaternion(0,0,0,0);

    // Angular velocity of the rigidbody
    Vector3D * rotation_ = new Vector3D(0,0,0);

    // Angular damping
    float angularDamping_ = 0;

    // Accumulated Torque (added by the force generator)
    Vector3D * accumTorque_ = new Vector3D(0,0,0);

    // Transform matrix (from orientation & rotation)
    // TODO change for new type
    Matrix * transformMatrix = new Matrix(3);

    /**
     * Calculates the transform matrix and normalizes the orientation
     */
    void calculateDerivedData();

    /**
     * Adds a force at a point of the rigidbody, and generates torque
     * WARNING: the point is a worldpoint (world-relative coordinates)
     * If only body-relative coordinates are available, use addForcesAtBodyPoint()
     */
    void addForcesAtWorldPoint(Vector3D force, Vector3D point);

    /**
     * Adds a force at a point of the rigidbody, and generates torque
     * WARNING: the point is a bodypoint (body-relative coordinates), prefer using addForcesAtWorldPoint() instead
     * If only world-relative coordinates are available, use addForcesAtWorldPoint()
     */
    void addForcesAtBodyPoint(Vector3D force, Vector3D point);

    /**
     * Clears the accumulated forces
     */
    void clearAccum();
};

#endif // RIGIDBODY_H
