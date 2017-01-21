#include "cube.h"

cube::cube()
{
}

void cube::getF(){
    F = G + H;
}

void cube::getG(int g){
    G = g;
}

void cube::getH(int h){
    H = h;
}

void cube::getStatus(int sta){
    status = sta;
}

void cube::setLeftPoint(cube *p){
    left = p;
}

void cube::setRightPoint(cube *p){
    right = p;
}

void cube::setDownPoint(cube *p){
    down = p;
}

void cube::setUpPoint(cube *p){
    up = p;
}

void cube::setLeft_UpPoint(cube *p){
    left_up = p;
}

void cube::setRight_UpPoint(cube *p){
    right_up = p;
}

void cube::setLeft_DownPoint(cube *p){
    left_down = p;
}

void cube::setRight_DownPoint(cube *p){
    right_down = p;
}

void cube::setParentPoint(cube *p){
    parent = p;
}
