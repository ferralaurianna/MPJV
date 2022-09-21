#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deltatime = 100;
    connect(this->timer, SIGNAL(timeout()), this, SLOT(UpdateFrame()));
    timer->start(deltatime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Management of the keyboard interactions
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
            case Qt::Key_P:
            {
                ui->gameGUI->forwardCamera();
                break;
            }
            case Qt::Key_K:
            {
                ui->gameGUI->turnLeftCamera();
                break;
            }
            case Qt::Key_L:
            {
                ui->gameGUI->backwardCamera();
                break;
            }
            case Qt::Key_M:
            {
                ui->gameGUI->turnRightCamera();
                break;
            }

        // Default case
        default:
        {
            // Ignore the event
            event->ignore();
            return;
        }
    }

    // Acceptation of the event and update rendering
    event->accept();
    ui->gameGUI->update();
}

// Updating the position and speed of the particle, timing it to get framerate
void MainWindow::UpdateFrame(QVector3D position, QVector3D speed, QVector3D acceleration)
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    QVector3D newpos = position + speed * deltatime + 0.5 * acceleration * deltatime * deltatime ;
    QVector3D newspeed = speed + acceleration * deltatime;
    position = newpos;
    speed = newspeed;

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    // Calculate time elapsed
    std::chrono::duration<double> elapsed = finish - start;
    deltatime = elapsed.count();
    timer->setInterval(deltatime);
}
