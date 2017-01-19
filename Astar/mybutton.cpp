#include "mybutton.h"
#include <QMessageBox>
myButton::myButton(Coord coord):QPushButton()
{
    this->m_coord = coord;
    connect(this,SIGNAL(clicked()),this,SLOT(btClicked()));
}

void myButton::setCoord(Coord newCd){
    m_coord = newCd;
}

Coord myButton::getCoord()const{
    return m_coord;
}

void myButton::btClicked(){
    emit myClick(this);
}

void myButton::setStatus(int sta){
    status = sta;
}
