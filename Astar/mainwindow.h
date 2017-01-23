#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "mybutton.h"
#include "cube.h"

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
    myButton *buttonArr[40][40];

    QPushButton *StartPoint;
    QPushButton *BlockPoint;
    QPushButton *FinalPoint;
    QPushButton *FindRoadBtn;
    QPushButton *NewGameBtn;
    QLabel *TitleLabel;

    int situation = - 1; // -1: not allowed, 0: start point, 1: block point, 2: block point

    int StartPointCount = 1;
    int BlockPointCount = 0;
    int FinalPointCount = 1;

    cube *cubeArr[40][40];

private slots:

    void on_StartPoint_Clicked();
    void on_BlockPoint_Clicked();
    void on_FinalPoint_Clicked();
    void on_FindRoadBtn_Clicked();
    void on_NewGameBtn_Clicked();
    void on_button_Clicked(myButton *p);
    //cube on_Cube_Clicked(cube *c);
};

#endif // MAINWINDOW_H
