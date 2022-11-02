#include "gametimer2.h"

GameTimer2::GameTimer2()
{
    timer.setSingleShot(true);
    timer.setInterval(9999 * 1000);
}

void GameTimer2::drawGameTimer(QPaintDevice *device) {

    QString strTime = QString::number(9999 - timer.remainingTime() / 1000);

    QPainter painter(device);
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 36));
    painter.drawText(355, -240, device->width(), device->height(), Qt::AlignCenter, strTime);
    painter.end();
}

void GameTimer2::startGameTimer(int time_) {
    timer.setInterval(time_ * 1000);
    timer.start();
}

