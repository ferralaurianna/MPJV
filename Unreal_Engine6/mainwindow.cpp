#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::nextFrame, this, &MainWindow::UpdateFrame);
    connect(this->timerStart, &QTimer::timeout, this, &MainWindow::UpdateFrame);
    timerStart->setSingleShot(true);
    timerStart->start(100/6);
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
//        case Qt::Key_P:
//        {
//            ui->gameGUI->forwardCamera();
//            break;
//        }
//        case Qt::Key_K:
//        {
//            ui->gameGUI->turnLeftCamera();
//            break;
//        }
//        case Qt::Key_L:
//        {
//            ui->gameGUI->backwardCamera();
//            break;
//        }
//        case Qt::Key_M:
//        {
//            ui->gameGUI->turnRightCamera();
//            break;
//        }
//        case Qt::Key_Z:
//        {
//            ui->gameGUI->forwardCamera();
//            break;
//        }
//        case Qt::Key_A:
//        {
//            ui->gameGUI->turnLeftCamera();
//            break;
//        }
//        case Qt::Key_S:
//        {
//            ui->gameGUI->backwardCamera();
//            break;
//        }
//        case Qt::Key_E:
//        {
//            ui->gameGUI->turnRightCamera();
//            break;
//        }
//        case Qt::Key_W:
//        {
//            ui->gameGUI->zoomIn();
//            break;
//        }
//        case Qt::Key_X:
//        {
//            ui->gameGUI->zoomOut();
//            break;
//        }
//        case Qt::Key_Control:
//        {
//            ui->gameGUI->goDown();
//            break;
//        }
//        case Qt::Key_Space:
//        {
//            ui->gameGUI->goUp();
//            break;
//        }
        case Qt::Key_Left:
        {
            ui->gameGUI->gun->angGunIncr(1);
            break;
        }
        case Qt::Key_Right:
        {
            ui->gameGUI->gun->angGunIncr(0);
            break;
        }
        case Qt::Key_Up:
        {
            ui->gameGUI->gun->elevationGunIncr(1);
            break;
        }
        case Qt::Key_Down:
        {
            ui->gameGUI->gun->elevationGunIncr(0);
            break;
        }
        case Qt::Key_Enter:
        {
            ui->gameGUI->launchPart();
            break;
        }
        case Qt::Key_Space:
        {
            ui->gameGUI->launchPart();
            break;
        }
//        case Qt::Key_T:
//        {
//            ui->gameGUI->scene->moveTarget();
//            break;
//        }
        case Qt::Key_Control:
        {
            ui->gameGUI->switchPartType();
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
void MainWindow::UpdateFrame()
{
    timerStart->start(deltatime);
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    for(Particles* particle : ui->gameGUI->particles)
    {
        particle->integrer(deltatime/1000.f);
    }

    // Update the position of the particle
    ui->gameGUI->update();

    ui->gameGUI->setFocus();
    ui->score->setText("SCORE : " + QString::number(ui->gameGUI->getScore()));

    switch(ui->gameGUI->getPartType())
    {
        case 0:
        {
            ui->indicPart->setStyleSheet("border-image: url(:/ballLogo.png)");
            break;
        }
        case 1:
        {
            ui->indicPart->setStyleSheet("border-image: url(:/canonballLogo.png)");
            break;
        }
        case 2:
        {
            ui->indicPart->setStyleSheet("border-image: url(:/fireballLogo.png)");
            break;
        }
        case 3:
        {
            ui->indicPart->setStyleSheet("border-image: url(:/laserballLogo.png)");
            break;
        }
    }

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    // Calculate time elapsed
    deltatime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    deltatime = deltatime/1000000.f;
    cout<<deltatime<<endl;

}
