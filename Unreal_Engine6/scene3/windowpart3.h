#ifndef WINDOWPART3_H
#define WINDOWPART3_H

#include "utils/Vector3D.h"
#include "menu/windowmainmenu.h"
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
    float deltatimeLogic = 0;

    QTimer *timerRender = new QTimer(this);
    float deltatimeRender = 0;

    void keyPressEvent(QKeyEvent * event);

    Vector3D movements= Vector3D(0,0,0);

    void updateInputs();
};

#endif // WINDOWPART3_H
