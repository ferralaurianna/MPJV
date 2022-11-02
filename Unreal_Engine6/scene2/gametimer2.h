#ifndef GAMETIMER2_H
#define GAMETIMER2_H

#include <QPainter>
#include <QTimer>

class GameTimer2 : public QObject
{
    Q_OBJECT

public:
    GameTimer2();

    QTimer timer;
    QTimer shrinkTimer;

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

    /**
     * @brief gameOver
     * A function to call when the game ends
     * @return A string containing the final game time
     */
    int gameOver();

public slots:

    /**
     * @brief shrinkBlob
     * Only here to emit the blobShrinkSignal
     */
    void shrinkBlob();

signals:

    void blobShrinkSignal();
};

#endif // GAMETIMER2_H
