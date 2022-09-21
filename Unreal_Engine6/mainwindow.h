#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <chrono>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer = new QTimer(this);
    float deltatime;
    bool hasFinishedLoop_=true;

private:
    Ui::MainWindow *ui;
    void UpdateFrame();

protected:
    void keyPressEvent(QKeyEvent * event);
};
#endif // MAINWINDOW_H
