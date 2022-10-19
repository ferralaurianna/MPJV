#ifndef WINDOWPART2_H
#define WINDOWPART2_H

#include <QMainWindow>

namespace Ui {
class WindowPart2;
}

class WindowPart2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowPart2(QWidget *parent = nullptr);
    ~WindowPart2();

private:
    Ui::WindowPart2 *ui;
};

#endif // WINDOWPART2_H
