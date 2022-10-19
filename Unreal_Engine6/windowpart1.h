#ifndef WINDOWPART1_H
#define WINDOWPART1_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>
#include <QKeyEvent>
#include "utils/particles.h"

namespace Ui {
class WindowPart1;
}

class WindowPart1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowPart1(QWidget *parent = nullptr);
    ~WindowPart1();

private:
    Ui::WindowPart1 *ui;
    void UpdateFrame();
    QTimer *timerStart = new QTimer(this);
    QTimer *timerInit = new QTimer(this);
    float deltatime;
    bool hasFinishedLoop_=true;
    int compteurInit = 0;

protected:
    void keyPressEvent(QKeyEvent * event);
    void init();
};

#endif // WINDOWPART1_H
