#include "windowpart2.h"
#include "ui_windowpart2.h"

WindowPart2::WindowPart2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPart2)
{
    ui->setupUi(this);
}

WindowPart2::~WindowPart2()
{
    delete ui;
}
