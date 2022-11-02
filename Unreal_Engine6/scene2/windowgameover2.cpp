#include "windowgameover2.h"
#include "menu/windowmainmenu.h"
#include "ui_windowgameover2.h"

QString hoverStyleSheet2 = "color: white;\nfont-size: 24px;\nbackground-color: #404040;\nborder-radius: 6px;\nborder: 1px solid #808080;\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0  #505050, stop:1 #606060);";

WindowGameOver2::WindowGameOver2(int finalTime, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowGameOver2)
{
    this->finalTime = finalTime;
    ui->setupUi(this);
    ui->finalTimeValue->setText(QString::number(finalTime) + " s");
}

WindowGameOver2::~WindowGameOver2()
{
    delete ui;
}

void returnToMenu()
{
    WindowMainMenu *window = new WindowMainMenu;
    window->show();
}

void WindowGameOver2::on_returnButton_clicked()
{
    returnToMenu();
    this->hide();
}

void WindowGameOver2::on_returnButton_pressed()
{
    ui->returnButton->setStyleSheet(hoverStyleSheet2);
}

