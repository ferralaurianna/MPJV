#ifndef WINDOWPART2_H
#define WINDOWPART2_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>
#include <QKeyEvent>
#include "utils/ParticlesSystem/collisiondetector.h"
#include "utils/ParticlesSystem/collisionregistrery.h"
#include "utils/ParticlesSystem/forceregistrery.h"
#include "utils/ParticlesSystem/particles.h"
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

public slots:
    void endGame();

private:
    Ui::WindowPart2 *ui;
    void UpdateFrame();
    QTimer *timerStart = new QTimer(this);
    float deltatime = 0;
    ForceRegistrery* registrery = new ForceRegistrery();

    CollisionRegistrery* registeryCol_ = new CollisionRegistrery();

    std::vector<std::vector<Polygone>*>* sceneWalls_ = new std::vector<std::vector<Polygone>*>();

    CollisionDetector detectorScene_ = CollisionDetector(registeryCol_,sceneWalls_);

    Vector3D movements= Vector3D(0,0,0);

    float jumpTimer = 0;

protected:
    void keyPressEvent(QKeyEvent * event);
};

#endif // WINDOWPART2_H
