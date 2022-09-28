#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>
#include <QTime>

#include "utils/particles.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void UpdateFrame();
    QTime start;
    QTime end;
    QTimer *timerStart = new QTimer(this);
    QTime* time = new QTime;
    float deltatime;
    bool hasFinishedLoop_=true;

protected:
    void keyPressEvent(QKeyEvent * event);
signals:
    void nextFrame();
};
#endif // MAINWINDOW_H
