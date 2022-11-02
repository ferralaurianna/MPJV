#ifndef GAMETIMER2_H
#define GAMETIMER2_H

#include <QPainter>
#include <QTimer>

class GameTimer2
{
public:
    GameTimer2();

    QTimer timer;

    /**
     * @brief startTimer
     * A function starting the game timer with [seconds] seconds
     */
    void startGameTimer(int seconds);

    /**
     * @brief drawTimer
     * A function used to draw the countdown timer on screen.
     */
    void drawGameTimer(QPaintDevice *device);

};

#endif // GAMETIMER2_H
