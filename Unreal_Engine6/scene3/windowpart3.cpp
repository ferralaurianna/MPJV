#include "windowpart3.h"
#include "menu/windowmainmenu.h"
#include "ui_windowpart3.h"

WindowPart3::WindowPart3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPart3)
{
    ui->setupUi(this);
    timerStart->setSingleShot(true);
//    timerInit->setSingleShot(true);
    timerStart->start(100/60);
//    timerInit->start(1000);
}

WindowPart3::~WindowPart3()
{
    delete ui;
}

// Management of the keyboard interactions
void WindowPart3::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
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
//    ui->gameGUI->update();
}

// Updating the position and speed of the particle, timing it to get framerate
void WindowPart3::UpdateFrame()
{
    timerStart->start(deltatime);
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Update the position of the particle
//    ui->gameGUI->update();

//    ui->gameGUI->setFocus();


    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    // Calculate time elapsed
    deltatime = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    deltatime = deltatime/1000000.f;
}
