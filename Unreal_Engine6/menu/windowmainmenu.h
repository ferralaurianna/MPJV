#ifndef WINDOWMAINMENU_H
#define WINDOWMAINMENU_H

#include <QMainWindow>

namespace Ui {
class WindowMainMenu;
}

class WindowMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowMainMenu(QWidget *parent = nullptr);
    ~WindowMainMenu();

private slots:
    void on_phase1Button_clicked();

    void on_phase2Button_clicked();

    void on_phase1Button_pressed();

    void on_phase2Button_pressed();

private:
    Ui::WindowMainMenu *ui;
};

#endif // WINDOWMAINMENU_H
