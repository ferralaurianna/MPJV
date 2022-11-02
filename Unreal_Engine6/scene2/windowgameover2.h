#ifndef WINDOWGAMEOVER2_H
#define WINDOWGAMEOVER2_H

#include <QMainWindow>

namespace Ui {
class WindowGameOver2;
}

class WindowGameOver2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowGameOver2(int finalTime, QWidget *parent = nullptr);
    ~WindowGameOver2();

private slots:
    void on_returnButton_clicked();

    void on_returnButton_pressed();

private:
    Ui::WindowGameOver2 *ui;
    int finalTime;
};

#endif // WINDOWGAMEOVER2_H
