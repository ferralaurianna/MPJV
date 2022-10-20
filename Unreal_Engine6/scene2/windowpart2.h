#ifndef WINDOWPART2_H
#define WINDOWPART2_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>
#include <QKeyEvent>
#include "utils/particles.h"

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

protected:
    void keyPressEvent(QKeyEvent * event);
    void init();
};

#endif // WINDOWPART2_H
