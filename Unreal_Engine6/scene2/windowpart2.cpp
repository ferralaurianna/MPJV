#include "windowpart2.h"
#include "generators/gravitygenerator.h"
#include "menu/windowmainmenu.h"
#include "ui_windowpart2.h"
#include "windowgameover2.h"

WindowPart2::WindowPart2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPart2)
{
    ui->setupUi(this);
    connect(this->timerStart, &QTimer::timeout, this, &WindowPart2::UpdateFrame);
    timerStart->setSingleShot(true);
    timerStart->start(100/60);

    connect(ui->gameGUI->gameTimer, SIGNAL(timeout()), this, SLOT(endGame()) );
}

WindowPart2::~WindowPart2()
{
    delete ui;
    delete registrery;
}

void WindowPart2::UpdateFrame()
{
    if(switch_<120)
    {
        switch_++;
    }
    else
    {
        switch_=0;
    }
    timerStart->start(deltatime);
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    for(Blob* blob : ui->gameGUI->blobs_)
    {
        vector<Blob::Link>* links = blob->getSprings();
        for(Blob::Link link: *links)
        {
            registrery->add(link.part1,new SpringTwoParticle(link.part2,0.05,link.l0));
            registrery->add(link.part2,new SpringTwoParticle(link.part1,0.05,link.l0));
        }
        blob->getNucleus()->addForces(Vector3D(-80+160*(switch_<60),0,-80+160*(switch_<60)));
    }

//    for(Blob* blob : ui->gameGUI->blobs_)
//    {
//        vector<Particles*>* particles = blob->getExteriorRow();
//        for(Particles* part : *particles)
//        {
//            GravityGenerator * graveGen = new GravityGenerator();
//            registrery->add(part,graveGen);
//        }
//        particles = blob->getInteriorRow();
//        for(Particles* part : *particles)
//        {
//            GravityGenerator * graveGen = new GravityGenerator();
//            registrery->add(part,graveGen);
//        }
//        GravityGenerator * graveGen = new GravityGenerator();
//        registrery->add(blob->getNucleus(),graveGen);
//    }


    registrery->updateForces(deltatime);
    registrery->clear();

    for(Blob* blob : ui->gameGUI->blobs_)
    {
        vector<Particles*>* particles = blob->getExteriorRow();
        for(Particles* part : *particles)
        {
            part->integrer(deltatime);
            part->clearAccum();
        }
        particles = blob->getInteriorRow();
        for(Particles* part : *particles)
        {
            part->integrer(deltatime);
            part->clearAccum();
        }
        blob->getNucleus()->integrer(deltatime);
        blob->getNucleus()->clearAccum();
    }

    // Update the position of the particle
    ui->gameGUI->update();
    ui->gameGUI->setFocus();

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    // Calculate time elapsed
    deltatime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    deltatime = deltatime/1000000.f;
}

void WindowPart2::keyPressEvent(QKeyEvent * event)
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
        case Qt::Key_Z:
        {
            ui->gameGUI->forwardCamera();
            break;
        }
        case Qt::Key_A:
        {
            ui->gameGUI->turnLeftCamera();
            break;
        }
        case Qt::Key_S:
        {
            ui->gameGUI->backwardCamera();
            break;
        }
        case Qt::Key_E:
        {
            ui->gameGUI->turnRightCamera();
            break;
        }
        case Qt::Key_W:
        {
            ui->gameGUI->zoomIn();
            break;
        }
        case Qt::Key_X:
        {
            ui->gameGUI->zoomOut();
            break;
        }
        case Qt::Key_Control:
        {
            ui->gameGUI->goDown();
            break;
        }
        case Qt::Key_Space:
        {
            ui->gameGUI->goUp();
            break;
        }
        case Qt::Key_R:
        {
            this->endGame();
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
    ui->gameGUI->update();
}

void WindowPart2::endGame() {
    qDebug() << "game ended";
    int finalTime = ui->gameGUI->gameTimer->gameOver();
    qDebug() << finalTime;
    WindowGameOver2 *window = new WindowGameOver2(finalTime);
    window->show();
    this->hide();
}
