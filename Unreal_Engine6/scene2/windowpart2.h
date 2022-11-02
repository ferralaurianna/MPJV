#ifndef WINDOWPART2_H
#define WINDOWPART2_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>
#include <QKeyEvent>
#include "utils/particles.h"
#include "utils/forceregistrery.h"
#include "generators/springtwoparticle.h"

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
    int switch_ = 0;

protected:
    void keyPressEvent(QKeyEvent * event);
};

#endif // WINDOWPART2_H
