#include "windowpart4.h"
#include "menu/windowmainmenu.h"
#include "ui_windowpart4.h"

Windowpart4::Windowpart4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Windowpart4)
{
    ui->setupUi(this);

    physic_ = PhysicSystem();

    actorlist_ = ActorList();

    actorlist_.setPhysic(&physic_);

    ui->gameGui4->setactorList(&actorlist_);

    connect(this->timerLogic, &QTimer::timeout, this, &Windowpart4::updateLogic);
//    timerLogic->setSingleShot(true);
    timerLogic->start(deltatimeLogic);

    connect(this->timerRender, &QTimer::timeout, this, &Windowpart4::updateRender);
//    timerRender->setSingleShot(true);
    timerRender->start(deltatimeRender);

    //connect(this->timerFakeCollision, &QTimer::timeout, this, &Windowpart4::FakeCollision);
    //connect(physic_, SIGNAL(collisionFoundSignal()), this, SLOT(endSimulation()));
}

Windowpart4::~Windowpart4()
{
    delete ui;
}

void Windowpart4::updateLogic()
{
    if(runSim)
    {
        updateInputs();
        physic_.UpdateForces(deltatimeLogic/1000);
        actorlist_.integrateAll(deltatimeLogic/1000);
    //    actorlist_.clearForces();
    }
}

void Windowpart4::updateRender()
{
    ui->gameGui4->update();
}

void Windowpart4::updateInputs()
{
    physic_.removeForce(0,-3);
    Actors* actor0 = actorlist_.getActor(0);
    if(actor0!=nullptr)
    {
        physic_.addSimpleForce(actor0->getRigidbody(),0,-3,movements*1000);
    }
}

void Windowpart4::endSimulation()
{
    runSim = false;
}


void Windowpart4::keyPressEvent(QKeyEvent * event)
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
        case Qt::Key_1:
        {
            //timerFakeCollision->stop();
            ui->gameGui4->demo();
            actorlist_.getActor(0)->getRigidbody()->addForcesAtBodyPoint(Vector3D(100000,100000,0),Vector3D(10,10,10));
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
