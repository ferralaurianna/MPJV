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
    QTimer *timerStart = new QTimer(this);
    QTimer *timerInit = new QTimer(this);
    float deltatime;
    bool hasFinishedLoop_=true;
    int compteurInit = 0;

protected:
    void keyPressEvent(QKeyEvent * event);
    void init();
};
#endif // MAINWINDOW_H
