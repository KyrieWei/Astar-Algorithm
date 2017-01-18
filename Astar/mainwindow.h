#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "button.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

public:
    button *buttonArr[40][40];

    QPushButton *StartPoint;
    QPushButton *BlockPoint;
    QPushButton *FinalPoint;

    int situation ; // 0: start point, 1: block point, 2: block point

    int startPointCount;
    int BlockPointCount;
    int FinalPointCount;

private slots:

    void on_StartPoint_Clicked();
    void on_BlockPoint_Clicked();
    void on_FinalPoint_Clicked();
    //void on_button_Clicked(button *p);
};

#endif // MAINWINDOW_H
