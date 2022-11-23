#ifndef WINDOWPART3_H
#define WINDOWPART3_H

#include "scene3/actorlist.h"
#include "utils/Vector3D.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMainWindow>

namespace Ui {
class WindowPart3;
}

class WindowPart3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowPart3(QWidget *parent = nullptr);
    ~WindowPart3();

private:
    Ui::WindowPart3 *ui;

    void updateLogic();

    void updateRender();

    QTimer *timerLogic = new QTimer(this);
    float deltatimeLogic = 1000/200;

    QTimer *timerRender = new QTimer(this);
    float deltatimeRender = 1000/60;

    void keyPressEvent(QKeyEvent * event);

    Vector3D movements= Vector3D(0,0,0);

    void updateInputs();

    PhysicSystem physic_;

    ActorList actorlist_;
};

#endif // WINDOWPART3_H
