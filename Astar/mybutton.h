#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>

struct Coord{
    int x;
    int y;
};

class myButton:public QPushButton
{
    Q_OBJECT
private:
    Coord m_coord;

public:
    explicit myButton(Coord coord);

    int status;
    void setCoord(Coord newCd);
    void setStatus(int sta);
    Coord getCoord() const;

signals:
    void myClick(myButton *p);
private slots:
    void btClicked();
};

#endif // MYBUTTON_H
