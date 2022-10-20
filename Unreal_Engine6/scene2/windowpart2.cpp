#include "windowpart2.h"
#include "ui_windowpart2.h"

WindowPart2::WindowPart2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPart2)
{
    ui->setupUi(this);
    connect(this->timerStart, &QTimer::timeout, this, &WindowPart2::UpdateFrame);
    timerStart->setSingleShot(true);
    timerStart->start(100/60);
}

WindowPart2::~WindowPart2()
{
    delete ui;
}

void WindowPart2::UpdateFrame()
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

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    // Calculate time elapsed
    deltatime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    deltatime = deltatime/1000000.f;
}
