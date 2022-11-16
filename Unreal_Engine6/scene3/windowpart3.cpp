#include "windowpart3.h"
#include "ui_windowpart3.h"

WindowPart3::WindowPart3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPart3)
{
    ui->setupUi(this);

    connect(this->timerLogic, &QTimer::timeout, this, &WindowPart3::updateLogic);
//    timerLogic->setSingleShot(true);
    timerLogic->start(deltatimeLogic);

    connect(this->timerRender, &QTimer::timeout, this, &WindowPart3::updateRender);
//    timerRender->setSingleShot(true);
    timerRender->start(deltatimeRender);
}

WindowPart3::~WindowPart3()
{
    delete ui;
}

void WindowPart3::updateLogic()
{

}

void WindowPart3::updateRender()
{
    updateInputs();
}

void WindowPart3::updateInputs()
{

}


void WindowPart3::keyPressEvent(QKeyEvent * event)
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
//        case Qt::Key_R:
//        {
//            this->endGame();
//            break;
//        }
        case Qt::Key_Up:
        {
            movements=movements+Vector3D(0,0,1);
            break;
        }
        case Qt::Key_Down:
        {
            movements=movements+Vector3D(0,0,-1);
            break;
        }
        case Qt::Key_Left:
        {
            movements=movements+Vector3D(1,0,0);
            break;
        }
        case Qt::Key_Right:
        {
            movements=movements+Vector3D(-1,0,0);
            break;
        }
        case Qt::Key_Space:
        {
            movements=movements+Vector3D(0,1,0);
            break;
        }
        case Qt::Key_Escape:
        {
            WindowMainMenu *window = new WindowMainMenu();
            window->show();
            this->hide();
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
}
