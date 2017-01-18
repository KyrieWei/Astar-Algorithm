#include <qpushbutton.h>
#ifndef BUTTON_H
#define BUTTON_H


class button:public QPushButton {
public:
    button();

    int xPos;
    int yPos;
    int H;
    int G;
    int F;
    int status; //status = 0: start point, 1: block point, 2: final point

    void setPoint(int x, int y);

    void setH(int h);

    void setG(int g);

    void setF(int f);

    void setStatus(int sta);

    void getCoordinate(int x, int y);

signals:

    void on_button_Click(button *p);

private slots:

    void buttonClicked();
};

#endif // BUTTON_H
