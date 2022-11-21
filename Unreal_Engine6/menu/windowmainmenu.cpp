#include "windowmainmenu.h"
#include "scene1/windowpart1.h"
#include "scene2/windowpart2.h"
#include "scene3/windowpart3.h"
#include "ui_windowmainmenu.h"

QString hoverStyleSheet = "color: white;\nfont-size: 24px;\nbackground-color: #404040;\nborder-radius: 6px;\nborder: 1px solid #808080;\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0  #505050, stop:1 #606060);";

WindowMainMenu::WindowMainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowMainMenu)
{
    ui->setupUi(this);
}

WindowMainMenu::~WindowMainMenu()
{
    delete ui;
}

void startPhase1()
{
    WindowPart1 *window = new WindowPart1;
    window->show();
}

void startPhase2()
{
    WindowPart2 *window = new WindowPart2;
    window->show();
}

void startPhase3()
{
    WindowPart3 *window = new WindowPart3;
    window->show();
}

void WindowMainMenu::on_phase1Button_clicked()
{
    startPhase1();
    this->hide();
}


void WindowMainMenu::on_phase2Button_clicked()
{
    startPhase2();
    this->hide();
}


void WindowMainMenu::on_phase1Button_pressed()
{
    ui->phase1Button->setStyleSheet(hoverStyleSheet);
}


void WindowMainMenu::on_phase2Button_pressed()
{
    ui->phase2Button->setStyleSheet(hoverStyleSheet);
}


void WindowMainMenu::on_phase3Button_clicked()
{
    startPhase3();
    this->hide();
}

