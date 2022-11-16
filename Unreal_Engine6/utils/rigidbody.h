#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "quaternion.h"


class Rigidbody
{
public:

    /**
     * @brief Rigidbody
     * posX, posY, posZ, radius, mass, velocity, orientation, angular velocity
     * The constructor of the Rigidbody class, with many physical variables as parameters.
     */
    Rigidbody(float posX=0,float posY=0,float posZ=0,float mass=1,Quaternion * orientation=new Quaternion());
    ~Rigidbody();

    // Getters / Setters
    Quaternion * getOrientation(){ return orientation_ ; };
    void setOrientation(Quaternion * orientation){ orientation_ = orientation; };
    Vector3D * getAngularVelocity(){ return angularVelocity_ ; };
    void setAngularVelocity(Vector3D * angularVelocity){ angularVelocity_ = angularVelocity; };

    /**
     * Integrates the rigidbody, by modifiying position, orientation & velocity
     * @param duration seconds
     */
    void integrate(float duration);

    //Getters/setters
    float getInverseMass(){return inverseMass_;};
    void setInverseMass(float inverseMass){inverseMass_=inverseMass;};
    Vector3D* getInitialVelocity(){return velocity_;};
    void setVelocity(Vector3D *velocity){velocity_=velocity;};

    //Add here the getter/setter of the position vector
    Vector3D* getPosition(){return position_;};
    Vector3D* getForces(){return accumForce_;};
    void setPosition(Vector3D *position){position_=position;};

    void addForces(Vector3D force);
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


    void clearAccum();

protected:

    //Initialize the gravity, damping and type of Particles (protected to have access in derived class)
    float damping_ = 0;
    Vector3D *accumForce_ = new Vector3D();

    Vector3D *position_ = new Vector3D();
    Vector3D *velocity_ = new Vector3D();
    Vector3D *angularVelocity_ = new Vector3D();

    float inverseMass_;

    // Orientation of the rigidbody
    Quaternion * orientation_ = new Quaternion();

    // Angular damping
    float angularDamping_ = 0;

    // Accumulated Torque (added by the force generator)
    Vector3D * accumTorque_ = new Vector3D();

    // Transform matrix (from orientation & rotation)
    // TODO change for new type
    Matrix * transformMatrix = new Matrix(3);
};

#endif // RIGIDBODY_H
