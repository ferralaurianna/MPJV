#ifndef WINDOWPART2_H
#define WINDOWPART2_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>
#include <QKeyEvent>
#include "utils/collisiondetector.h"
#include "utils/collisionregistrery.h"
#include "utils/particles.h"
#include "utils/forceregistrery.h"
#include "generators/springtwoparticle.h"
#include "generators/springflotability.h"

namespace Ui {
class WindowPart2;
}

class WindowPart2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit WindowPart2(QWidget *parent = nullptr);
    ~WindowPart2();

private:
    Ui::WindowPart2 *ui;
    void UpdateFrame();
    QTimer *timerStart = new QTimer(this);
    float deltatime = 0;
    ForceRegistrery* registrery = new ForceRegistrery();
    int switch_ = 0;

    CollisionRegistrery* registeryCol_ = new CollisionRegistrery();

    vector<vector<Polygone>*>* sceneWalls_ = new vector<vector<Polygone>*>();

    CollisionDetector detectorScene_ = CollisionDetector(registeryCol_,sceneWalls_);

protected:
    void keyPressEvent(QKeyEvent * event);
};

#endif // WINDOWPART2_H
