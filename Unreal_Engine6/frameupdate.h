#ifndef FRAMEUPDATE_H
#define FRAMEUPDATE_H

#include <QTimer>
#include <QVector3D>
#include <chrono>

class frameupdate : public QObject
{
private:

    float deltatime = 100;
    QTimer *timer = new QTimer(this);

public:
    // Constructor
    frameupdate();

    // Destructor
    virtual ~frameupdate();

    // Setters
    void Setdt(float dt);

    // Getters
    float Getdt() {return deltatime;}

    // Update the position and speed of the particle
    void UpdateFrame(QVector3D position, QVector3D speed, QVector3D acceleration);

    // Update the framerate
    void UpdateFramerate();

    //
    void MainLoop();

};

#endif // FRAMEUPDATE_H
