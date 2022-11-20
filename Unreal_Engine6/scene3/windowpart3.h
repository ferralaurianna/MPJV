#ifndef WINDOWPART3_H
#define WINDOWPART3_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>
#include <QKeyEvent>

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
    void UpdateFrame();
    QTimer *timerStart = new QTimer(this);
    float deltatime = 0;

protected:
    void keyPressEvent(QKeyEvent * event);
    void init();
};

#endif // WINDOWPART3_H
