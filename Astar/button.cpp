#include "button.h"
button::button():QPushButton(){
   // connect(this, SIGNAL(Click()),this,SLOT(buttonClicked()));
}

void button::setPoint(int x, int y){
    this->xPos = x;
    this->yPos = y;
}

void button::setG(int g){
    this->G = g;
}

void button::setH(int h){
    this->H = h;
}

void button::setF(int f){
    this->F = f;
}

void button::setStatus(int sta){
    this->status = sta;
}
/*
void button::buttonClicked(){
      on_button_Click(this);
}
*/
void button::getCoordinate(int x, int y){
    x = this->xPos;
    y = this->yPos;
}

