#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
