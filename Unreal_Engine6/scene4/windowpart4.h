#ifndef WINDOWPART4_H
#define WINDOWPART4_H

#include "scene3/actorlist.h"
#include "utils/Vector3D.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMainWindow>

namespace Ui {
class Windowpart4;
}

class Windowpart4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Windowpart4(QWidget *parent = nullptr);
    ~Windowpart4();

private:
    Ui::Windowpart4 *ui;

    void updateLogic();

    void updateRender();

    void FakeCollision();

    QTimer *timerLogic = new QTimer(this);
    float deltatimeLogic = 1000/200;

    QTimer *timerRender = new QTimer(this);
    float deltatimeRender = 1000/60;

    QTimer *timerFakeCollision = new QTimer(this);

    void keyPressEvent(QKeyEvent * event);

    Vector3D movements= Vector3D(0,0,0);

    void updateInputs();

    PhysicSystem physic_;

    ActorList actorlist_;
};

#endif // WINDOWPART4_H
